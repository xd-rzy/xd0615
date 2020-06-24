int i=0,m=0;
void setup()
{	
  for(i=0;i<7;i++){
  pinMode(i, OUTPUT);

  }
  for(m=6;m>=0;m--){
    pinMode(m, OUTPUT);}
}

void loop()
{
    for(i=0;i<7;i++){
  for(m=6-i;m>=0;){
  digitalWrite(m, HIGH);
  delay(50); // Wait for 1000 millisecond(s)
  digitalWrite(m, LOW);
  delay(50); // Wait for 1000 millisecond(s)
  digitalWrite(i, HIGH);
  delay(50); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
  delay(50); // Wait for 1000 millisecond(s)
  break;
  }}
  for(i=0;i<7;i++){
  digitalWrite(i, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  for(m=6;m>=0;m--){
  digitalWrite(m, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(m, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  }
   }
  for(m=6;m>=0;m--){
  digitalWrite(m, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(m, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  for(i=0;i<7;i++){
  digitalWrite(i, HIGH);
  delay(50); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
  delay(50); // Wait for 1000 millisecond(s)
  }}

}
