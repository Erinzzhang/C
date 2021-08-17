#include <stdio.h>

int main() {
    // get data form chip
    unsigned char buf[7] = {0x00, 0x0b, 0x0b,0x0,0x03,0x96,0x43};
    for(int i = 0; i < 7; i++)
        printf("0x%x ",buf[i]);
    printf("\n\n");
    
    // HEX to float (sol 3:pointer)
    float val = *(float*) &buf[3];
    printf("val = %f\n",val);
    
    if (val > 255 || val < 0)
    {
        printf("out of value!\n");
    }
    else
    {
        unsigned char temp = (unsigned char) val;
        printf("temp : %d\n", temp);
    }
    
    
    // HEX to float (sol 1:for loop)
    printf("==== sol 1 ====\n");
    unsigned char buf2[4];
    for(int i = 0; i < 4; i++)
    {
        buf2[i] = buf[i+3];
        printf("0x%x ",buf2[i]);
    }
    printf("\n");
    float *a = (float*) buf2;
    printf("*a = %f\n\n",*a);
    
    // HEX to float (sol 2:pointer)
    printf("==== sol 2 ====\n");
    unsigned char *p = &buf[3];
    float *b = (float*) p;
    printf("*b = %f\n\n",*b);
    
    printf("==== pointer ====\n");
    printf("unsigned char *p = &buf[3]\n");
    printf("*p     = 0x%x\n",*p);
    printf("*(p+1) = 0x%x\n",*(p+1));
    printf("*(p+2) = 0x%x\n",*(p+2));
    printf("*(p+3) = 0x%x\n\n",*(p+3));
    
    printf("*p+1 = 0x%x\n",*p+1);
    printf("(*p)+1 = 0x%x\n",(*p)+1);
    printf("*(p+1) = 0x%x\n\n",*(p+1));
    
    printf("*(p+2) = 0x%x\n",*(p+2));
    printf("*(p+2)+1 = 0x%x\n",*(p+2)+1);
    printf("*(p)+2 = 0x%x\n",*(p)+2);
    printf("(*p)+2 = 0x%x\n",(*p)+2);
    printf("*p+2 = 0x%x\n\n",*p+2);;
    
    printf("p[0] = 0x%x\n",p[0]);
    printf("p[1] = 0x%x\n",p[1]);
    printf("p[2] = 0x%x\n",p[2]);
    printf("p[3] = 0x%x\n\n",p[3]);
    
    printf("p[0]+1 = 0x%x\n",p[0]+1);
    
    
    return 0;
}
