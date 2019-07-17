// LogicScheme.cpp : Defines the entry point for the console application.

//”словие задачи смотри в ][акере 01.04(второй пазл)
//программа выводит все возможные варианты,
//начина€ с low и заканчива€ high. 4<=low<=high<=MAX_SHORT
//»де€ решени€ состоит в том, что кажда€ операци€ на рисунке представлена функцией.
// огда к функции приходит пакет данных типа block, она выполн€ет свою логическую операцию
//над значением + ставит штамп на этот пакет о прохождении данной точки + посылает пакет
//по всем своим линкам (в том числе и предыдущей функции).

#include "stdafx.h"
using namespace std;
const short low = 4; //нижн€€ граница и 
const short high = 20;//верхн€€ граница вывода вариантов
struct block
	{
		short value;
		short max;
		short path[high];
		short count;
	};
void n1(block);
void n2(block);
void n3(block);
void n4(block);
void n5(block);
void n6(block);
void n7(block);
void n8(block);
void n9(block);
void n10(block);
void n11(block);
void n12(block);
void n13(block);
void n14(block);
void PrintPath(block &);
const short in_out =0x2a;

int _tmain(int argc, _TCHAR* argv[])
{
	block _packet;

	for (short i=low;i<=high;i++)
	{
		_packet.value = in_out;
		_packet.max = i;
		_packet.count = 0;
		n1(_packet);
		n2(_packet);
		n3(_packet);
    	cin.get(); // если эту строку закомментировать, то будут выведены сразу все возможные варианты решени€
	}
	return 0;
}
void n1(block packet)
{
	packet.value&=0x34;
	packet.path[packet.count++]=1;
	if (packet.count<packet.max)
	{
		n2(packet);
        n4(packet);
		n5(packet);
		n6(packet);
		n7(packet);
	}
}
void n2(block packet)
{
	packet.value^=0x34;
	packet.path[packet.count++]=2;
	if (packet.count<packet.max)
	{
		n1(packet);
        n3(packet);
		n4(packet);
		n5(packet);
		n6(packet);
		n7(packet);
	}
}
void n3(block packet)
{
	packet.value|=0x34;
	packet.path[packet.count++]=3;
	if (packet.count<packet.max)
	{
		n2(packet);
        n4(packet);
		n5(packet);
		n6(packet);
		n7(packet);
	}
}
void n4(block packet)
{
	packet.value|=0x3f;
	packet.path[packet.count++]=4;
	if (packet.count<packet.max)
	{
		n1(packet);
		n2(packet);
        n3(packet);
		n5(packet);
		n8(packet);
		n9(packet);
		n10(packet);
	}
}
void n5(block packet)
{
	packet.value|=0x1a;
	packet.path[packet.count++]=5;
	if (packet.count<packet.max)
	{
		n1(packet);
		n2(packet);
        n3(packet);
		n4(packet);
		n6(packet);
		n8(packet);
		n9(packet);
		n10(packet);
	}
}
void n6(block packet)
{
	packet.value&=0x38;
	packet.path[packet.count++]=6;
	if (packet.count<packet.max)
	{		
		n1(packet);
		n2(packet);
        n3(packet);
		n5(packet);
		n7(packet);
		n8(packet);
		n9(packet);
		n10(packet);
	}
}
void n7(block packet)
{
	packet.value^=0x02;
	packet.path[packet.count++]=7;
	if (packet.count<packet.max)
	{	
		n1(packet);
		n2(packet);
        n3(packet);
		n6(packet);
		n8(packet);
		n9(packet);
		n10(packet);
	}
}
void n8(block packet)
{
	packet.value|=0x1a;
	packet.path[packet.count++]=8;
	if (packet.count<packet.max)
	{		
		n4(packet);
		n5(packet);
        n6(packet);
		n7(packet);
		n9(packet);
		n11(packet);
		n12(packet);
		n13(packet);
		n14(packet);
	}
}
void n9(block packet)
{
	packet.value^=0x25;
	packet.path[packet.count++]=9;
	if (packet.count<packet.max)
	{
		n4(packet);
		n5(packet);
        n6(packet);
		n7(packet);
		n8(packet);
		n10(packet);
		n11(packet);
		n12(packet);
		n13(packet);
		n14(packet);
	}
}
void n10(block packet)
{
	packet.value^=0x3a;
	packet.path[packet.count++]=10;
	if (packet.count<packet.max)
	{
		n4(packet);
		n5(packet);
        n6(packet);
		n7(packet);
		n9(packet);
		n11(packet);
		n12(packet);
		n13(packet);
		n14(packet);
	}
}
void n11(block packet)
{
	packet.value&=0x2a;
	packet.path[packet.count++]=11;
	if (packet.value==in_out && packet.count==packet.max)
	{
	    PrintPath(packet);
        
	}
	else if (packet.count<packet.max)
	{
		n12(packet);
		n8(packet);
        n9(packet);
		n10(packet);
	}
}
void n12(block packet)
{
	packet.value|=0x0a;
	packet.path[packet.count++]=12;
	if (packet.value==in_out && packet.count==packet.max)
	{	
		PrintPath(packet);
		
	}
	else if (packet.count<packet.max)
	{
		n11(packet);
		n13(packet);
		n8(packet);
        n9(packet);
		n10(packet);
	}
}
void n13(block packet)
{
	packet.value^=0x3f;
	packet.path[packet.count++]=13;
	if (packet.value==in_out && packet.count==packet.max)
	{
		PrintPath(packet);
		
	}
	else if (packet.count<packet.max)
	{
		n12(packet);
		n14(packet);
		n8(packet);
        n9(packet);
		n10(packet);
	}
}
void n14(block packet)
{
	packet.path[packet.count++]=14;
	packet.value&=0x0e;
	if (packet.value==in_out && packet.count==packet.max)
	{
		PrintPath(packet);
		
	}
	else if (packet.count<packet.max)
	{
		n13(packet);
		n8(packet);
        n9(packet);
		n10(packet);
	}
}
void PrintPath(block &pack)
{
	cout << "Success path:";  
	for (short i=0;i<pack.count;i++)
	{
		cout <<" " << pack.path[i];
	}
	cout << endl;
}

