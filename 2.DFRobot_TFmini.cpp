#include <DFRobot_TFmini.h>

void      DFRobot_TFmini::begin(Stream &s_)
{
    TFSerial = &s_;
    TFSerial->begin(115200);
}

bool      DFRobot_TFmini::measure(void)
{
    uint8_t       TFbuff[9] = {0};
    long          checksum  = 0 ;
    while(TFSerial->available()){
        TFbuff[0] = TFSerial->read();
        checksum += TFbuff[0];
        if(TFbuff[0] == 'Y'){
            TFbuff[1] = TFSerial->read();
            checksum += TFbuff[1];
            if(TFbuff[1] == 'Y'){
                for(int i = 2;i < 8;i++){
                    TFbuff[i] = TFSerial->read();
                    checksum += TFbuff[i];
                }
                TFbuff[8] = TFSerial->read();
                checksum &= 0xff;
                if(checksum == TFbuff[8]){
                    distance = TFbuff[2]+TFbuff[3]*256;
                    strength = TFbuff[4]+TFbuff[5]*256;
                    return true;
                }else{
                    checksum  = 0;
                }
            }else{
                checksum  = 0;
            }
        }else{
            checksum  = 0;
        }
    }
    return false;
}
//comment_changed
uint16_t  DFRobot_TFmini::getDistance(void)
{
    return distance;
}

uint16_t  DFRobot_TFmini::getStrength(void)
{
    return strength;

}
//testing_myself_2
//testing_myself
//comment_changed    
//new_feature
//pushing code Feb branch


//testing_myself_3
//testing_myself_4
//testing_myself_5
