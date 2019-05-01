#include <Servo.h>

Servo servo_pin_3;
Servo servo_pin_5;
Servo servo_pin_6;
double _ABVAR_1_A2 = 0.0 ;
double _ABVAR_2_difA = 0.0 ;
double _ABVAR_3_difB = 0.0 ;
double _ABVAR_4_difC = 0.0 ;
double _ABVAR_5_numA = 0.0 ;
double _ABVAR_6_numB = 0.0 ;
double _ABVAR_7_pointA = 0.0 ;
double _ABVAR_8_pointB = 0.0 ;
double _ABVAR_9_pointC = 0.0 ;
double _ABVAR_10_average = 0.0 ;

void sA();
void sB();
void sC();

void setup()
{
  servo_pin_3.attach(3);
  servo_pin_5.attach(5);
  servo_pin_6.attach(6);
  Serial.begin(9600);
  servo_pin_3.write( 37 );

  servo_pin_5.write( 37 );

  servo_pin_6.write( 37 );

  delay( 3000 );

}

void loop()
{
  sA();
  sB();
  sC();
  _ABVAR_1_A2 = map ( analogRead(2) , 0 , 1023 , 0 , 180 )  ;
  servo_pin_3.write( ( ( _ABVAR_1_A2 * ( _ABVAR_2_difA / 100.0 ) ) + 37 ) );
  servo_pin_5.write( ( ( _ABVAR_1_A2 * ( _ABVAR_3_difB / 100.0 ) ) + 37 ) );
  servo_pin_6.write( ( ( _ABVAR_1_A2 * ( _ABVAR_4_difC / 100.0 ) ) + 37 ) );
  Serial.print(_ABVAR_5_numA);
  Serial.println();
  Serial.print(_ABVAR_6_numB);
  Serial.println();
}

void sC()
{
  _ABVAR_7_pointA = sqrt( ( pow( ( 0.0 - _ABVAR_5_numA ) ,2.0 ) + pow( ( -400.0 - _ABVAR_6_numB ) ,2.0 ) ) ) ;
  _ABVAR_8_pointB = sqrt( ( pow( ( -346.4 - _ABVAR_5_numA ) ,2.0 ) + pow( ( 200.0 - _ABVAR_6_numB ) ,2.0 ) ) ) ;
  _ABVAR_9_pointC = sqrt( ( pow( ( 346.4 - _ABVAR_5_numA ) ,2.0 ) + pow( ( 200.0 - _ABVAR_6_numB ) ,2.0 ) ) ) ;
  _ABVAR_10_average = ( ( ( _ABVAR_7_pointA + _ABVAR_8_pointB ) + _ABVAR_9_pointC ) / 3 ) ;
  _ABVAR_2_difA = map ( _ABVAR_7_pointA , 1.0 , 400.0 , 0.0 , 100.0 )  ;
  _ABVAR_3_difB = map ( _ABVAR_8_pointB , 0.0 , 400.0 , 0.0 , 100.0 )  ;
  _ABVAR_4_difC = map ( _ABVAR_9_pointC , 0.0 , 400.0 , 0.0 , 100.0 )  ;
}

void sB()
{
  _ABVAR_6_numB = map ( analogRead(1) , 0 , 1023 , -100 , 100 )  ;
}

void sA()
{
  _ABVAR_5_numA = map ( analogRead(0) , 0 , 1023 , -100 , 100 )  ;
}

