#include <unistd.h>
#include <stdio.h>


void	print_bits(unsigned char octet)
{
	return(octet >> 4) | (octet << 4);
}

int main(int argc,char **argv)
{
	print_bits(2);
}
