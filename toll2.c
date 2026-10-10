
#include <pic.h>


void delay(void);
void delay1(void);

void cmd(int a);
void data(char b);
void display(const char *p);

char key(void);

void trans(char x);
char rec(void);

void vehicleProcess(char *password, int fee, const char *vehicle);
int getAmount(void);
void displayNumber(int number);
void motor(void);




void main()
{
    char pass2[4] = {'1','2','3','4'};
    char pass4[4] = {'A','B','C','D'};
    char passH[4] = {'A','B','1','2'};

    ADCON1 = 0x07;

    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x9C;
    TRISD = 0x0F;

    
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 129;

    
    cmd(0x38);
    cmd(0x0E);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);

    while(1)
    {
       
        if(RC2 == 0)
        {
            vehicleProcess(pass2, 100, "2 WHEELER");
        }

        
        else if(RC3 == 0)
        {
            vehicleProcess(pass4, 200, "4 WHEELER");
        }

        
        else if(RC4 == 0)
        {
            vehicleProcess(passH, 500, "HEAVY");
        }
    }
}




void vehicleProcess(char *password, int fee, const char *vehicle)
{
    char entered[4];
    int i;
    int count = 0;

    int amount;
    int balance;

   
    cmd(0x01);

    cmd(0x80);
    display(vehicle);

    
    cmd(0xC0);
    display("PASSWORD:");

    for(i = 0; i < 4; i++)
    {
        entered[i] = key();
        data(entered[i]);
    }

    
    for(i = 0; i < 4; i++)
    {
        if(password[i] == entered[i])
        {
            count++;
        }
    }

    
    if(count == 4)
    {
        cmd(0x01);

        cmd(0x80);
        display("ACCESS GRANTED");

        cmd(0xC0);
        display("FEE : RS");

        displayNumber(fee);

        delay();

        
        amount = getAmount();

        
        balance = amount - fee;

        
        cmd(0x01);

        cmd(0x80);
        display("AMT PAID=");

        displayNumber(amount);

        cmd(0xC0);
        display("BALANCE=");

        displayNumber(balance);

        delay();

        
        motor();

        cmd(0x01);
    }

    
    else
    {
        cmd(0x01);

        cmd(0x80);
        display("WRONG PASSWORD");

        delay();

        cmd(0x01);
    }
}




int getAmount(void)
{
    char c;
    char d;
    char e;

    int amount;

    c = rec();
    d = rec();
    e = rec();

    
    c = c - 48;
    d = d - 48;
    e = e - 48;

    amount = c * 100 + d * 10 + e;

    return amount;
}




void displayNumber(int number)
{
    char p;
    char q;
    char r;

    p = (number / 100) + '0';
    q = ((number % 100) / 10) + '0';
    r = (number % 10) + '0';

    data(p);
    data(q);
    data(r);
}




void motor(void)
{
    
    PORTA = 0x2D;
    delay1();

    PORTA = 0x00;
    delay1();

   
    PORTA = 0x36;
    delay1();

    PORTA = 0x00;
    delay1();
}




char key(void)
{
    int e;

    while(1)
    {
       
        PORTD = 0x7F;
        e = PORTD & 0x0F;

        switch(e)
        {
            case 0x07: return('1');
            case 0x0B: return('2');
            case 0x0D: return('3');
            case 0x0E: return('4');
        }


        
        PORTD = 0xBF;
        e = PORTD & 0x0F;

        switch(e)
        {
            case 0x07: return('5');
            case 0x0B: return('6');
            case 0x0D: return('7');
            case 0x0E: return('8');
        }


       
        PORTD = 0xDF;
        e = PORTD & 0x0F;

        switch(e)
        {
            case 0x07: return('9');
            case 0x0B: return('0');
            case 0x0D: return('*');
            case 0x0E: return('#');
        }


       
        PORTD = 0xEF;
        e = PORTD & 0x0F;

        switch(e)
        {
            case 0x07: return('A');
            case 0x0B: return('B');
            case 0x0D: return('C');
            case 0x0E: return('D');
        }
    }
}




void display(const char *p)
{
    while(*p != '\0')
    {
        data(*p);
        p++;
    }
}



void cmd(int a)
{
    PORTB = a;

    RC0 = 0;
    RC1 = 1;

    delay();

    RC1 = 0;
}



void data(char b)
{
    PORTB = b;

    RC0 = 1;
    RC1 = 1;

    delay();

    RC1 = 0;
}



void trans(char x)
{
    TXREG = x;

    while(TXIF == 0);

    TXIF = 0;
}




char rec(void)
{
    while(RCIF == 0);

    return RCREG;
}



void delay(void)
{
    int i;
    int j;

    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 500; j++);
    }
}


void delay1(void)
{
    int i;
    int j;

    for(i = 0; i < 1500; i++)
    {
        for(j = 0; j < 1500; j++);
    }
}

