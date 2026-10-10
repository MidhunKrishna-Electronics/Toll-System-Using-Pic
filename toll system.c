#include<pic.h>
void delay();
void delay1();
void cmd(int a);
void data(char b);
char key();
void display(const char *p);
void trans(char x);
char rec();
void main()


{
	int i,f,count=0;
	char a[4]="1234";
	char b[4];
	char m[4]="ABCD";
	char n[4];
	char g[4]="AB12";
	char h[4];
	char c,d,e,p,q,r;	
	ADCON1=0x07;
	TRISA=0x00;
	TRISB=0x00;
	TRISC=0x9C;
	TRISD=0x0F;
	TXSTA=0x24;
	RCSTA=0x90;
	SPBRG=129;
	
	cmd(0x38);
	cmd(0x0E);
	cmd(0x06);
	cmd(0x01);
	cmd(0x80);
	
	


	
	while (1)
		{
		if (RC2==0)
		{
            cmd(0x80);
            display("2 WHEELER");

            cmd(0xC0);
            display("PASSWORD:");

            for(i=0;i<4;i++)
            {
                b[i]=key();
                data(b[i]);         
            }
  count=0;

            for(i=0;i<4;i++)
            {
                if(a[i]==b[i])
				{
                    count++;
				}
            }

            if(count==4)
            {
                cmd(0x01);

                cmd(0x80);
                display("ACCESS GRANTED");

                cmd(0xC0);
                display("FEE : RS100");
                delay();
			
	
			c=rec();
			d=rec();
			e=rec();
			c=c-48;
			d=d-48;
			e=e-48;
			f=c*100+d*10+e;
			f=f-100;

			cmd(0x01);
			cmd(0x80);
            display(" amt paid");
			cmd(0xC0);
			display("balance=");

			p=((f/100)+48);
			data(p);
			q=(((f%100)/10)+48);
			data(q);
			r=((f%10)+48);
			data(r);
		
			 

		
			PORTA=0X2D;
			delay1();
			PORTA=0x00;
			delay1();
				
			PORTA=0X36;
			delay1();
			PORTA=0x00;
			delay1();
			cmd(0x01);
		
			}
 			 else
            	{
                cmd(0x01);

                cmd(0x80);
                display("WRONG password");
				cmd(0x01);
				}
		
			}
				else if (RC3==0)
		{
            cmd(0x80);
            display("4 WHEELER");

            cmd(0xC0);
            display("PASSWORD:");

            for(i=0;i<4;i++)
            {
                n[i]=key();
                data(n[i]);         
            }
  count=0;

            for(i=0;i<4;i++)
            {
                if(m[i]==n[i])
				{
                    count++;
				}
            }

            if(count==4)
            {
                cmd(0x01);

                cmd(0x80);
                display("ACCESS GRANTED");

                cmd(0xC0);
                display("FEE : RS200");
                delay();
			
	
			c=rec();
			d=rec();
			e=rec();
			c=c-48;
			d=d-48;
			e=e-48;
			f=c*100+d*10+e;
			f=f-200;

			cmd(0x01);
			cmd(0x80);
            display(" amt paid");
			cmd(0xC0);
			display("balance=");

			p=((f/100)+48);
			data(p);
			q=(((f%100)/10)+48);
			data(q);
			r=((f%10)+48);
			data(r);
		
			 

		
			PORTA=0X2D;
			delay1();
			PORTA=0x00;
			delay1();
				
			PORTA=0X36;
			delay1();
			PORTA=0x00;
			delay1();
			cmd(0x01);
		
			}
 			 else
            	{
                cmd(0x01);

                cmd(0x80);
                display("WRONG password");
				cmd(0x01);
				}
		
			}
		else if (RC4==0)
		{
            cmd(0x80);
            display("heavy");

            cmd(0xC0);
            display("PASSWORD:");

            for(i=0;i<4;i++)
            {
                h[i]=key();
                data(h[i]);         
            }
  count=0;

            for(i=0;i<4;i++)
            {
                if(g[i]==h[i])
				{
                    count++;
				}
            }

            if(count==4)
            {
                cmd(0x01);

                cmd(0x80);
                display("ACCESS GRANTED");

                cmd(0xC0);
                display("FEE : RS500");
                delay();
			
	
			c=rec();
			d=rec();
			e=rec();
			c=c-48;
			d=d-48;
			e=e-48;
			f=c*100+d*10+e;
			f=f-500;

			cmd(0x01);
			cmd(0x80);
            display(" amt paid");
			cmd(0xC0);
			display("balance=");

			p=((f/100)+48);
			data(p);
			q=(((f%100)/10)+48);
			data(q);
			r=((f%10)+48);
			data(r);
		
			 

		
			PORTA=0X2D;
			delay1();
			PORTA=0x00;
			delay1();
				
			PORTA=0X36;
			delay1();
			PORTA=0x00;
			delay1();
			cmd(0x01);
		
			}
 			 else
            	{
                cmd(0x01);

                cmd(0x80);
                display("WRONG password");
				cmd(0x01);
 	 
		
				}
		}
	}
}

char key()
{
			int e;
			while(1)
			{
			PORTD=0x7F;
			e=PORTD&0x0f;
			switch(e)
			{
				case 0x07:return('1');
				break;
				case 0x0B:return('2');
				break;
				case 0x0D:return('3');
				break;
				case 0x0E:return('4');
				break;
			}
			PORTD=0xBF;
				e=PORTD&0x0f;
			switch(e)
			{
				case 0x07:return('5');
				break;
				case 0x0B:return('6');
				break;
				case 0x0D:return('7');
				break;
				case 0x0E:return('8');
				break;
			}
			PORTD=0xDF;
				e=PORTD&0x0f;
			switch(e)
			{
				case 0x07:return('9');
				break;
				case 0x0B:return('0');
				break;
				case 0x0D:return('*');
				break;
				case 0x0E:return('#');
				break;
			}
			PORTD=0xEF;
				e=PORTD&0x0f;
			switch(e)
			{
				case 0x07:return('A');
				break;
				case 0x0B:return('B');
				break;
				case 0x0D:return('C');
				break;
				case 0x0E:return('D');
				break;
			}
		 
		}
}

void display(const char *p)
{
	while(*p!='\0')
	{
		data(*p);
		p++;
	}
}
void cmd(int a)
{	
	PORTB=a;
	RC0=0;
	RC1=1;
	delay();
	RC1=0;
}
void data(char b)
{
	PORTB=b;
	RC0=1;
	RC1=1;
	delay();
	RC1=0;
}
void trans(char x)
{	
	TXREG=x;
	while(TXIF==0);
	TXIF=0;
}
char rec()
{
	while(RCIF==0);
	return(RCREG);
	RCIF=0;
}
void delay()
{
	int i,j;
	for(i=0;i<500;i++)
	for(j=0;j<500;j++);	
} 
void delay1()
{
	int i,j;
	for(i=0;i<1500;i++)
	for(j=0;j<1500;j++);	
	
}