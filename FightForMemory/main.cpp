extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
#include <SDL.h>


int main(int argc, char* argv[]) {
    AVFormatContext* pFormatCtx = NULL;
    int videoStream;
    AVCodecContext* pCodecCtx = NULL;
    const AVCodec* pCodec = NULL;
    AVFrame* pFrame = NULL;
    AVPacket packet;
    int frameFinished;
    SDL_Window* screen;
    SDL_Renderer* renderer;
    SDL_Texture* bmp;

    // Inicjuje SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);


    // Otwiera plik wideo
    avformat_open_input(&pFormatCtx, "test2.mp4", NULL, NULL);

    // Szuka strumienia wideo
    videoStream = -1;
    for (int i = 0; i < pFormatCtx->nb_streams; i++)
        if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
            break;
        }

    // Znajduje odpowiedni dekoder dla strumienia wideo
    pCodec = avcodec_find_decoder(pFormatCtx->streams[videoStream]->codecpar->codec_id);

    // Uzyskuje wska�nik na kontekst kodeka
    pCodecCtx = avcodec_alloc_context3(pCodec);
    avcodec_parameters_to_context(pCodecCtx, pFormatCtx->streams[videoStream]->codecpar);

    // Otwiera kodek
    avcodec_open2(pCodecCtx, pCodec, NULL);

    pFrame = av_frame_alloc();

    screen = SDL_CreateWindow("Moje wideo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pCodecCtx->width, pCodecCtx->height, 0);

    renderer = SDL_CreateRenderer(screen, -1, 0);
    bmp = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, pCodecCtx->width, pCodecCtx->height);


    double fps = av_q2d(pFormatCtx->streams[videoStream]->avg_frame_rate); // �rednia liczba klatek na sekund�
    Uint32 delay = (Uint32)(1000.0 / fps); // Czas op�nienia mi�dzy klatkami w milisekundach


    // Odczytuje plik
    while (av_read_frame(pFormatCtx, &packet) >= 0) {
        // Tylko strumienie wideo
        if (packet.stream_index == videoStream) {
            // Dekoduje wideo
            avcodec_send_packet(pCodecCtx, &packet);
            while (avcodec_receive_frame(pCodecCtx, pFrame) == 0) {
                // Rysuje ramk�
                SDL_UpdateYUVTexture(bmp, NULL, pFrame->data[0], pFrame->linesize[0], pFrame->data[1], pFrame->linesize[1], pFrame->data[2], pFrame->linesize[2]);

                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, bmp, NULL, NULL);
                SDL_RenderPresent(renderer);
                SDL_Delay(delay); // Op�nienie synchronizuj�ce z FPS
            }
        }
        av_packet_unref(&packet);
    }

    // Czyszczenie
    av_frame_free(&pFrame);
    avcodec_free_context(&pCodecCtx);
    avformat_close_input(&pFormatCtx);

    return 0;
}
