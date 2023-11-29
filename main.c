#include <mcs51reg.h>
unsigned char msg[65] = {"Incremente o PWM com + e decremente com -   PWD ATUAL: "};
int pwmAtual = 0;

void pwm(int ciclo){
    P3_2 = 1; // NL1
    P3_3 = 0;
    if (ciclo == 10){
        // Configurar 2 ms (ciclo de trabalho 10%)
        TH0 = 0xF8;
        TL0 = 0x2F;
    }
    if (ciclo == 20){
        // Configurar 4 ms (ciclo de trabalho 20%)
        TH0 = 0xF0;
        TL0 = 0x5F;
    }
    if (ciclo == 30){
        // Configurar 6 ms (ciclo de trabalho 30%)
        TH0 = 0xE8;
        TL0 = 0x8F;
    }
    if (ciclo == 40){
        // Configurar 8 ms (ciclo de trabalho 40%)
        TH0 = 0xE0;
        TL0 = 0xBF;
    }
    if (ciclo == 50){
        // Configurar 10 ms (ciclo de trabalho 50%)
        TH0 = 0xD8;
        TL0 = 0xEF;
    }
    if (ciclo == 60){
        // Configurar 12 ms (ciclo de trabalho 60%)
        TH0 = 0xD1;
        TL0 = 0x1F;
    }
    if (ciclo == 70){
        // Configurar 14 ms (ciclo de trabalho 70%)
        TH0 = 0xC9;
        TL0 = 0x4F;
    }
    if (ciclo == 80){
         // Configurar 16 ms (ciclo de trabalho 80%)
        TH0 = 0xC1;
        TL0 = 0x7F;
    }
    if (ciclo == 90){
        // Configurar 18 ms (ciclo de trabalho 90%)
        TH0 = 0xB9;
        TL0 = 0xAF;
    }
    if (ciclo == 100){
        // Configurar 20 ms (ciclo de trabalho 100%)
        TH0 = 0xB1;
        TL0 = 0xDF;
    }

    TR0 = 1; // Ligar o timer
    // Aguardar 
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0; // Voltar para zero novamente
    P3_2 = 0; // NL0
    P3_3 = 1; 
    // Configurar 16 ms (espaço em branco)
    if (ciclo == 10){
        // Configurar 18 ms (espaço em branco)
        TH0 = 0xB9;
        TL0 = 0xAF;
    }
    if (ciclo == 20){
        // Configurar 16 ms (espaço em branco)
        TH0 = 0xC1;
        TL0 = 0x7F;
    }
    if (ciclo == 30){
        TH0 = 0xC9;
        TL0 = 0x4F;
    }
    if (ciclo == 40){
        TH0 = 0xD1;
        TL0 = 0x1F;
    }
    if (ciclo == 50){
        TH0 = 0xD8;
        TL0 = 0xEF;
    }
    if (ciclo == 60){
        TH0 = 0xE0;
        TL0 = 0xBF;
    }
    if (ciclo == 70){
        TH0 = 0xE8;
        TL0 = 0x8F;
    }
    if (ciclo == 80){
        TH0 = 0xF0;
        TL0 = 0x5F;
    }
    if (ciclo == 90){
        TH0 = 0xF8;
        TL0 = 0x2F;
    }
    if (ciclo == 100){
        TH0 = 0x00;
        TL0 = 0x00;
    }

    TR0 = 1; // Ligar o timer
    // Aguardar 
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
    P3_2 = 1; // NL1
    P3_3 = 0;
}

void pwm5(int ciclo){
    P3_2 = 1; // NL1
    P3_3 = 0;
    if (ciclo == 40){
        // Configurar 20 ms (ciclo de trabalho 40%)
        TH0 = 0xB1;
        TL0 = 0xDF;
    }
    if (ciclo == 50){
        // Configurar 25 ms (ciclo de trabalho 50%)
        TH0 = 0x9E;
        TL0 = 0x57;
    }
    if (ciclo == 90){
        // Configurar 45 ms (ciclo de trabalho 90%)
        TH0 = 0x50;
        TL0 = 0x37;
    }
    TR0 = 1; // Ligar o timer
    // Aguardar 20 ms
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0; // Voltar para zero novamente
    P3_2 = 0; // NL0
    P3_3 = 1;
    if (ciclo == 40){
        // Configurar 30 ms
    TH0 = 0x8A;
    TL0 = 0xCF;
    } 
    if (ciclo == 50){
        // Configurar 25 ms
        TH0 = 0x9E;
        TL0 = 0x57;
    }
    if (ciclo == 90){
        // Configurar 5 ms
        TH0 = 0xEC;
        TL0 = 0x77;
    } 
    
    TR0 = 1; // Ligar o timer
    // Aguardar 30 ms
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
    P3_2 = 1; // NL1
    P3_3 = 0;
}

void init_UART(){
    SM0 = 0;
    SM1 = 1;
    TMOD = 0X20;
    TL1 = 0XFD;
    TH1 = 0XFD;
    TR1 = 1;
    REN = 1;
    
}

void tx_UART(unsigned char ch){
    SBUF = ch;
    while(TI == 0);
    TI = 0;
}
void atualizarPWM(int pwmAtual) {
    if (pwmAtual > 100) {
        pwmAtual = 100;
    } else if (pwmAtual < 0) {
        pwmAtual = 0;
    }
}

void main(void){ 
   // Write your code here
    int controle;
    //Configurar o timer
    TMOD = 0x01;//Timer 0 no modo 1 contador de 16bits
    init_UART();
    for(int i = 0; i < 65; i++)
        tx_UART(msg[i]);

    SBUF = 0X0D;
   while (1){
        if(RI == 1){
            if(SBUF == '+'){
                if(pwmAtual <= 100){
                    pwmAtual += 10;
                    atualizarPWM(pwmAtual);
                    controle = 1;
                }
            }
            if(SBUF == '-'){
                if(pwmAtual >= 0){
                    pwmAtual -= 10;
                    atualizarPWM(pwmAtual);
                    controle = 1;
                }
            }
            RI = 0;
        }
            if(controle == 1)
            {
                if(pwmAtual == 10)
                    pwm(10);
                if(pwmAtual == 20)
                    pwm(20);
                if(pwmAtual == 30)
                    pwm(30);
                if(pwmAtual == 40)
                    pwm(40);
                if(pwmAtual == 50)
                    pwm(50);
                if(pwmAtual == 60)
                    pwm(60);
                if(pwmAtual == 70)
                    pwm(70);
                if(pwmAtual == 80)
                    pwm(80);
                if(pwmAtual == 90)
                    pwm(90);
                if(pwmAtual >= 100)
                    pwm(100);
            }
        if(P2_4 == 0 && P2_5 == 0 && P2_6 == 1)
            pwm(10);
        if(P2_4 == 0 && P2_5 == 1 && P2_6 == 0)
            pwm(20);
        if(P2_4 == 0 && P2_5 == 1 && P2_6 == 1)
            pwm(80);
        if(P2_4 == 1 && P2_5 == 0 && P2_6 == 1)
            pwm5(40);
        if(P2_4 == 1 && P2_5 == 1 && P2_6 == 0)
            pwm5(50);
        if(P2_4 == 1 && P2_5 == 1 && P2_6 == 1)
            pwm5(90);

        P3_2 = 0;
        P3_3 = 0;
    }
 }
