#ifndef POV_H_
#define POV_H_
#endif


#define NUM_LEDS 24
#define SCAN_RESOLUTION 18

const int colorLogo[32][NUM_LEDS] = {
  
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 8, 4,   4, 4, 8, 8,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 8, 8, 8,   8, 8, 8, 8,   8, 8, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 8, 7, 7,   4, 4, 4, 8,   3, 8, 8, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 8, 7, 0,   0, 0, 0, 0,   4, 3, 8, 8,   7, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 7,   8, 7, 0, 0,   0, 0, 4, 0,   0, 4, 3, 8,   8, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 7,   8, 0, 0, 8,   0, 4, 4, 0,   0, 0, 3, 8,   8, 7, 0, 0},

    {0, 0, 0, 0,   0, 0, 0, 7,   8, 0, 0, 8,   8, 4, 4, 8,   0, 0, 0, 4,   8, 7, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 7,   8, 0, 0, 0,   8, 4, 8, 8,   8, 0, 3, 4,   8, 7, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 4,   4, 0, 0, 0,   4, 4, 0, 8,   0, 0, 3, 4,   7, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 4,   4, 8, 0, 0,   0, 4, 0, 0,   3, 3, 4, 8,   7, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   4, 4, 7, 0,   0, 0, 0, 0,   4, 8, 8, 7,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 7, 7,   0, 0, 0, 7,   8, 8, 7, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 4, 7,   3, 7, 7, 8,   7, 7, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 4, 3,   8, 8, 8, 7,   0, 0, 0, 0,   0, 0, 0, 0},

    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 3, 8,   8, 4, 7, 7,   7, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 3, 8, 8,   7, 0, 4, 4,   7, 7, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   3, 3, 8, 7,   0, 0, 0, 4,   4, 7, 7, 8,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   3, 8, 8, 7,   0, 0, 0, 0,   0, 0, 7, 7,   8, 4, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   3, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 7,   8, 3, 4, 0},
    {0, 0, 0, 0,   0, 0, 0, 3,   7, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 0,   7, 3, 4, 0},
    {0, 0, 0, 0,   0, 0, 0, 3,   8, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 0,   8, 3, 4, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   8, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 0,   8, 3, 0, 0},

    {0, 0, 0, 0,   0, 0, 0, 0,   8, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 8,   8, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   8, 7, 7, 7,   0, 0, 0, 0,   0, 0, 7, 4,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 4, 7,   7, 0, 0, 7,   7, 7, 4, 4,   4, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 4, 8,   8, 7, 8, 8,   8, 8, 4, 4,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 4, 4,   7, 7, 7, 7,   4, 4, 3, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 3,   4, 4, 4, 4,   3, 3, 3, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   3, 3, 3, 3,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    
};

const int disp[18][NUM_LEDS] = {
  
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 2, 2, 2,   2, 3, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 2,   2, 3, 5, 3,   5, 3, 2, 3,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 2, 3,   5, 0, 7, 0,   7, 0, 5, 3,   2, 0, 0, 0},
	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 2, 5, 0,   7, 0, 0, 0,   0, 0, 7, 5,   3, 2, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   2, 3, 0, 7,   0, 0, 0, 0,   0, 0, 0, 7,   3, 2, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 2,   5, 0, 7, 0,   0, 0, 0, 0,   0, 0, 0, 5,   3, 2, 0, 0},
    {0, 0, 0, 0,   0, 0, 2, 0,   0, 7, 0, 0,   0, 0, 0, 0,   0, 0, 7, 3,   2, 0, 0, 0},

	
    {0, 0, 0, 0,   0, 3, 3, 5,   7, 0, 0, 0,   0, 0, 0, 0,   7, 5, 3, 2,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 2, 3, 0,   0, 0, 0, 0,   0, 0, 0, 0,   4, 5, 3, 2,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 2, 0,   5, 7, 0, 0,   0, 0, 0, 0,   0, 7, 5, 3,   2, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 2,   3, 0, 7, 0,   0, 0, 0, 0,   0, 0, 7, 5,   3, 2, 0, 0},
	
    {0, 0, 0, 0,   0, 0, 0, 0,   2, 5, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   3, 2, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 2, 5, 0,   7, 0, 0, 0,   0, 0, 7, 5,   3, 2, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 3, 2,   5, 0, 7, 0,   7, 0, 5, 3,   2, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   2, 2, 5, 5,   0, 5, 3, 2,   0, 0, 0, 0},

	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 3, 2,   3, 2, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0}	
    
};

const int disp2[26][NUM_LEDS] = {
  
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   5, 5, 5, 5,   5, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   5, 5, 5, 5,   5, 5, 5, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   5, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 0,   0, 0, 0, 5,   5, 0, 0, 0},
	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 5, 5, 0,   0, 0, 0, 5,   0, 0, 0, 0,   5, 5, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 5, 5, 0,   0, 0, 0, 5,   0, 0, 0, 0,   5, 5, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 5, 5, 0,   0, 5, 5, 5,   5, 5, 0, 0,   5, 5, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 5, 5, 0,   0, 0, 0, 5,   0, 0, 0, 5,   5, 0, 0, 0},

	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 5,   0, 0, 0, 5,   5, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   5, 0, 0, 0,   0, 5, 5, 5,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   5, 0, 0, 0,   5, 5, 5, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   5, 5, 5, 5,   5, 0, 0, 0,   0, 0, 0, 0},
	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 5, 5, 5,   5, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   5, 5, 5, 5,   5, 5, 5, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   5, 5, 0, 0,   0, 5, 5, 5,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   5, 0, 0, 0,   0, 0, 0, 5,   5, 0, 0, 0},

	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 0,   0, 0, 0, 0,   5, 5, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 5,   0, 0, 0, 0,   0, 5, 5, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 5,   0, 0, 0, 0,   0, 5, 5, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   0, 0, 0, 5,   0, 0, 0, 0,   0, 5, 5, 0},
	
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 5, 5,   5, 0, 0, 0,   0, 0, 0, 0,   5, 5, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   5, 0, 0, 0,   0, 0, 0, 5,   5, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 5,   5, 5, 5, 5,   5, 5, 5, 5,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 5, 5, 5,   5, 5, 0, 0,   0, 0, 0, 0},
	{0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0}
    
};
