#include <cs50.h>
#include <stdio.h>

int main(void) {
    int isbn = 0;

	isbn = get_int("ISBN: ");

    int temp = 0;

	for(int i = 10 ; i > 0 ; i-- )
	{
		temp += i * (isbn % 10);
		isbn = isbn / 10;
	}


	if(k % 11 == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}
