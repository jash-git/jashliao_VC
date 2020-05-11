#include<stdio.h>

typedef enum  { spring, summer, autumn, winter }seasons;
typedef enum  { spring_set = 1, summer_set = 2, autumn_set = 4, winter_set = 8}seasons_set;
typedef enum
{
        NACK_NONE                = 0x1000,
        NACK_TIMEOUT,                
        NACK_INVALID_BAUDRATE,        
        NACK_INVALID_POS,            
        NACK_IS_NOT_USED,            
        NACK_IS_ALREADY_USED,        
        NACK_COMM_ERR,                
        NACK_VERIFY_FAILED,            
        NACK_IDENTIFY_FAILED,        
        NACK_DB_IS_FULL,                
        NACK_DB_IS_EMPTY,            
        NACK_TURN_ERR,                
        NACK_BAD_FINGER,
        NACK_ENROLL_FAILED,
        NACK_IS_NOT_SUPPORTED,
        NACK_DEV_ERR,
        NACK_CAPTURE_CANCELED,
        NACK_INVALID_PARAM,
        NACK_FINGER_IS_NOT_PRESSED
};
int main()
{

    seasons s;

    s = spring;
    printf("spring = %d\n",s);
    s = summer;
    printf("summer = %d\n",s);
    s = autumn;
    printf("autumn = %d\n",s);
    s = winter;
    printf("winter = %d\n",s);

    seasons_set s_set;
    s_set = spring_set;
    printf("spring_set = %d\n",s_set);
    s_set = summer_set;
    printf("summer_set = %d\n",s_set);
    s_set = autumn_set;
    printf("autumn_set = %d\n",s_set);
    s_set = winter_set;
    printf("winter_set = %d\n",s_set); 

    printf("NACK_NONE=%d\n",NACK_NONE);
    printf("NACK_TIMEOUT=%d\n",NACK_TIMEOUT);
    return 0;
}