#include <stdio.h>
#include <stdlib.h>
#include "departUtils.h"

int main()
{
	depart *dep = initDepart(10, "������");
	for (int i = 0; i < 10; i++)
	{
		employee *entry = createEntry(100 + i, "Ա��", 0, 20 + i);
		appendTo(dep, entry);
	}
	displayAll(dep);

	system("pause");
	return 0;
}