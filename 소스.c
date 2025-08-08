#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mylist {
	int age;
	char name[32];
	char phone[32];
	struct mylist* pprev;
	struct mylist* pnext;
}mylist ;

mylist Headnode = { 0,"___Dummy Head___" };
mylist Tailnode = { 0,"___Dummy Tail___" };

void Initnode(void) {
	Headnode.pnext = &Tailnode;
	Tailnode.pprev = &Headnode;
}

void addmylist(int age, char* pname, char* pphone) {
	mylist* pNewuser = (mylist*)malloc(sizeof(mylist));
	pNewuser->age = age;
	strcpy_s(pNewuser->name,sizeof(pNewuser->name) , pname);
	strcpy_s(pNewuser->phone, sizeof(pNewuser->phone), pphone);



	Tailnode.pprev->pnext = pNewuser;
	pNewuser->pprev = Tailnode.pprev;
	pNewuser->pnext = &Tailnode;
	Tailnode.pprev = pNewuser;

	
		
		
	
}

mylist* Searchname(const char* pname) {
	mylist* Name = Headnode.pnext;
	while (Name != NULL) {
		if (strcmp(pname , Name->name)==0) {
		printf("\"%s\": founded\n", pname);
		return Name;
	}
		Name = Name->pnext;
		
			
	}
	printf("\"%s\": Not founded\n", pname);
	return NULL;
}

void PRINT(void) {
	mylist* ptmp = &Headnode;
	
	while (ptmp != NULL)
	{
		printf("[%p] %d, %s, %s [%p]\n",
			ptmp, ptmp->age, ptmp->name, ptmp->phone,
			ptmp->pnext);
		ptmp = ptmp->pnext;
	}
}





mylist* Searchtoremove2(const char* pname) {
	mylist* Name = Headnode.pnext;
	while (Name != NULL) {
		if (strcmp(pname, Name->name) == 0) {
			return Name;
		}
		Name = Name->pnext;


	}
	printf("\"%s\": Not founded\n", pname);
	return NULL;
}

void Remove(const char*pname) {
	mylist* premove = NULL;
	premove = Searchtoremove2(pname);
	if (premove != NULL) {
		premove->pnext->pprev = premove->pprev;
		premove->pprev->pnext = premove->pnext;
	}

	
	free(premove);


};

void DELETE(void) {

	mylist* ptmp = Headnode.pnext;
	mylist* delete;
	while (ptmp != NULL && ptmp != &Tailnode) {
		delete = ptmp;
		printf("delete: [%p] %d, %s, %s [%p]\n",
			ptmp, ptmp->age, ptmp->name, ptmp->phone,
			ptmp->pnext);
		ptmp = ptmp->pnext;
		free(delete);

	}
	Initnode();
}


void testcase1(void) {
	puts("testcase1------------------------------------------");
	addmylist(10, "Hoon", "010-1111-1111");
	addmylist(12, "choi", "010-2222-2222");
	addmylist(13, "jang", "010-3333-3333");
	PRINT();
	
	puts("remove: Hoon");
	Remove("Hoon");
	PRINT();
	DELETE();
	putchar('\n');
}

void testcase2(void) {
	puts("testcase2------------------------------------------");
	addmylist(10, "Hoon", "010-1111-1111");
	addmylist(12, "choi", "010-2222-2222");
	addmylist(13, "jang", "010-3333-3333");
	PRINT();

	puts("remove: choi");
	Remove("choi");
	PRINT();
	DELETE();
	putchar('\n');
}

void testcase3(void) {
	puts("testcase3------------------------------------------");
	addmylist(10, "Hoon", "010-1111-1111");
	addmylist(12, "choi", "010-2222-2222");
	addmylist(13, "jang", "010-3333-3333");
	PRINT();

	puts("remove: jang");
	Remove("jang");
	PRINT();
	DELETE();
	putchar('\n');
}

void testcase4(void) {
	puts("testcase4------------------------------------------");
	addmylist(10, "Hoon", "010-1111-1111");
	addmylist(12, "choi", "010-2222-2222");
	addmylist(13, "jang", "010-3333-3333");
	PRINT();

	puts("remove: jng");
	Remove("jng");
	PRINT();
	DELETE();
	putchar('\n');
}

int main(void)
{
	Initnode();
	testcase1();
	testcase2();
	testcase3();
	testcase4();
	return 0;

}
