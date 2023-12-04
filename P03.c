#INCLUDE <18f4550.h>
#FUSES NOPROTECT, NOWDT, NOLVP, HSPLL, PLL5, CPUDIV2
#USE delay(clock = 48M)
/*
#BYTE TRISB = 0xF93
#BIT B0 = 0xF81.0
#BIT IPEN = 0xFD0.7
#BYTE INTCON = 0xFF2

#BYTE TRISD = 0xF95
#BIT D025 = 0xF83.2
#BIT D150 = 0xF83.3
#BIT D275 = 0xF83.4

#BYTE TMR0H = 0xFD7
#BYTE TMR0L = 0xFD6
#BYTE T0CON = 0xFD5

int1 op1 = 0, op2 = 0;

#INT_TIMER0
void desbrT0(){
   B0 = !B0;
   
   if(op1 == 1 && B0 == 1){TMR0L =  0xE6; TMR0H =  0xFB;}
   else if(op1 == 1 && B0 == 0){TMR0L =  0xB6; TMR0H =  0xFE;}
   else if(op2 == 1 && B0 == 0){TMR0L =  0xE9; TMR0H =  0xFB;}
   else if(op2 == 1 && B0 == 1){TMR0L =  0xB9; TMR0H =  0xFE;}
   else {TMR0L = 0x51; TMR0H = 0xFD;} //FD51
}

void main(){
   IPEN = 0;
   INTCON = 0b10100000;
   TRISB = 0x00;
   TRISD = 0x07;
   T0CON = 0b10000000;
   TMR0L =  0x51;
   TMR0H =  0xFD;
   
   while(TRUE){
      if(D025){op1 = 1; op2 = 0;}
      else if(D150){op1 = 0; op2 = 0;}
      else if(D275){op1 = 0; op2 = 1;}
   }
   
}
*/

#int_TIMER0
void TIMER0_isr(){
   output_toggle(PIN_B0);
   set_timer0(64844);
}

void main(){
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2);
   set_timer0(64844);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(global);
   
   while(TRUE){}
}
