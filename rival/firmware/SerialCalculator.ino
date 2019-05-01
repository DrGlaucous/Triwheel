char _ABVAR_1_react = ' ' ;
double _ABVAR_2_pointA = 0.0 ;
double _ABVAR_3_numA = 0.0 ;
double _ABVAR_4_numB = 0.0 ;
double _ABVAR_5_pointB = 0.0 ;
double _ABVAR_6_pointC = 0.0 ;

void sA();
void sB();
void sC();

void setup()
{
  Serial.begin(9600);
  delay( 20 );

  Serial.print("ready to accept");
  Serial.println();

}

void loop()
{
  _ABVAR_1_react = Serial.read();
  if (( ( ( _ABVAR_1_react ) == ('X') ) || ( ( _ABVAR_1_react ) == ('x') ) ))
  {
    Serial.print("Ready to accept X coordinate");
    Serial.println();
    sA();
  }
  if (( ( ( _ABVAR_1_react ) == ('Y') ) || ( ( _ABVAR_1_react ) == ('y') ) ))
  {
    Serial.print("Ready to accept Y coordinate");
    Serial.println();
    sB();
  }
  if (( ( ( _ABVAR_1_react ) == ('C') ) || ( ( _ABVAR_1_react ) == ('c') ) ))
  {
    Serial.print("Calculating...");
    Serial.println();
    sC();
  }
}

void sC()
{
  _ABVAR_2_pointA = sqrt( ( pow( ( 0.0 - _ABVAR_3_numA ) ,2.0 ) + pow( ( -400.0 - _ABVAR_4_numB ) ,2.0 ) ) ) ;
  _ABVAR_5_pointB = sqrt( ( pow( ( -346.4 - _ABVAR_3_numA ) ,2.0 ) + pow( ( 200.0 - _ABVAR_4_numB ) ,2.0 ) ) ) ;
  _ABVAR_6_pointC = sqrt( ( pow( ( 346.4 - _ABVAR_3_numA ) ,2.0 ) + pow( ( 200.0 - _ABVAR_4_numB ) ,2.0 ) ) ) ;
  Serial.print("(T1) distance from x0 y-400:");
  Serial.print(map ( _ABVAR_2_pointA , 0 , 600 , 0 , 180 ) );
  Serial.println();
  Serial.print("(T2) distance from x-346.4 y200:");
  Serial.print(map ( _ABVAR_5_pointB , 0 , 600 , 0 , 180 ) );
  Serial.println();
  Serial.print("(T3) distance from x346.4 y200:");
  Serial.print(map ( _ABVAR_6_pointC , 0 , 600 , 0 , 180 ) );
  Serial.println();
}

void sA()
{
  _ABVAR_3_numA = Serial.parseInt() ;
  Serial.print(_ABVAR_3_numA);
  Serial.println();
}

void sB()
{
  _ABVAR_4_numB = Serial.parseInt() ;
  Serial.print(_ABVAR_4_numB);
  Serial.println();
}

