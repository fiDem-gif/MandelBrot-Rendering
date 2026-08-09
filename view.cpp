    #define SDL_MAIN_HANDLED
    #include <SDL2/SDL.h>
    #include <complex>
    #include <cmath>

    #define width 900
    #define height 600
    #define COLOR_WHITE 0xFFFFFFFF
    #define MANDEL_LIMIT 1000

    int max_iterations = 50;
    
    int check_4_mandelbrot(double real, double img, int max_iterations)
    {
        std::complex<double> c(real, img);
        std::complex<double> z(0,0);
        
        for (int i =0; i < max_iterations; i++)
        {
            z = pow(z,2) + c;
        }

        double real_part = z.real();
        double img_part = z.imag();
        return abs(z) < MANDEL_LIMIT;
    }

    void visualize_mandelbrot(SDL_Surface *psurface)
    {
        for (int x = 0; x < width; x++)
        {
            for (int y = 0 ; y < height; y++)
            {
                
                double real = -2.0 + ((double)x / width) * 3.0;
                double img = -1.0 + ((double)y / height) * 2.0;
                
                if ( check_4_mandelbrot((double) real , (double) img, max_iterations))
                {
                    SDL_Rect rect = {x,y, 1, 1};
                    SDL_FillRect(psurface, &rect, COLOR_WHITE);
                }
            }
        }
    }

    int main (){

        if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        {
            SDL_Log("SDL Init Error: %s", SDL_GetError());
            return 1;
        }
        // Window or canvas frame initialization and attributes
        SDL_Window  *window = SDL_CreateWindow(
            "MandelBrot Set",
            SDL_WINDOWPOS_CENTERED ,
            SDL_WINDOWPOS_CENTERED,
            width ,
            height ,
            0 );
                
            
        
        if(!window){
            SDL_Log("Failed to create window: %s", SDL_GetError());
            SDL_Quit();
            return 1;
        }
        
        
        
        SDL_Surface *psurface = SDL_GetWindowSurface(window);
        visualize_mandelbrot(psurface);
        
        int application_running = 1 ;
        while (application_running){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT) {
                    application_running = 0;
                }
                SDL_UpdateWindowSurface(window);

                SDL_Delay(16);
                
                
                
            }    
        }

    }