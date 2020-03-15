int ch_f[1][8][8] = {
  {{1,1,0,0,1,1,1,0},
   {1,1,0,1,1,1,0,0},
   {1,1,1,1,1,0,0,0},
   {1,1,1,1,0,0,0,0},
   {1,1,1,1,0,0,0,0},
   {1,1,1,1,1,0,0,0},
   {1,1,0,1,1,1,0,0},
   {1,1,0,0,1,1,1,0}}
};

void writeCol(unsigned char col_no, bool state){
  digitalWrite(col_no+2, state);
}
void writeRow(unsigned char row_no, bool state){
  digitalWrite(row_no+10, state);
}
void setPos(unsigned char row_no, unsigned char col_no){
  for(int count =0; count<8; count++){
    if(count == col_no){
      writeCol(count,HIGH);
    }
    else if (count == row_no) {
      writeRow(count,LOW);
    }
    else {
      writeCol(count,LOW);
      writeRow(count,HIGH);
    }
  }
}
void setup()
  {
    for(int i = 2; i<=18; i++) {
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);
    }
  }
void loop()
{
  for(int char_no=0; char_no < 2; char_no ++){
    for(int intend = 0; intend <100; intend++){
      for(int row=0; row<8; row++){
         for(int col=0; col<8; col++){
           if (ch_f[char_no][row][col] == 1){
             setPos(row, col);
           }
         }
      }
    }
  }
}
