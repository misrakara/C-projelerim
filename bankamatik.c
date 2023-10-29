#include<stdio.h>


int main()
{
	float bakiye=2000.0,kullanicimiktari= 0,gunluklimit=1000.0,havaletutari=0;
	int islem;
	printf("Merhaba,hosgeldiniz,\n Lutfen yapmak istediginiz islemi seciniz\n");
	printf("\n1->Para yatirma:\n2->Para cekme:\n3->Bakiye sorgulama:\n4->Havale islemi:",islem);
	scanf("%d",&islem);
	
	if(islem==1)
	{
		printf("Yatirmak istediginiz tutari giriniz:",kullanicimiktari);
		scanf("%f",&kullanicimiktari);
		bakiye+= kullanicimiktari;
		printf("Yeni bakiyeniz:%.2f\n",bakiye);
		printf("\n Isleminiz basariyla gerceklesti,Tesekkur ederiz.");	
	}
	
	else if(islem==2)
	{
		printf("Cekmek istediginiz tutari giriniz:",kullanicimiktari);
		scanf("%f",&kullanicimiktari);
		if(kullanicimiktari>bakiye)
		{
			printf("Bakiyeniz yetersiz\n");
		}
		else if(kullanicimiktari>gunluklimit)
		{
			printf("Gunluk para cekme limitinizi astiniz,islem gerceklesemiyor.\n");
		}
		else{
			bakiye-= kullanicimiktari;
			printf("Yeni bakiyeniz:%.2f\n",bakiye);	
			printf("\t Ýsleminiz basarýyla gerceklesti,Tesekkur ederiz.\n");
			
		}
		
	}

    else if(islem==3)
	{
		printf("\t Bakiyeniz:%.2f\n",bakiye);
		
	}
	else if(islem==4)
	{
		printf("Lutfen havale yapmak istediginiz tutari giriniz:\n",havaletutari);
		scanf("%f",&havaletutari);
		if(bakiye<havaletutari)
		{
			printf("Bakiyeniz yetersiz,\nhavale islem gerceklesemiyor.\n");	
		}
		else {
		
			bakiye-=havaletutari;
			printf("\tHavale isleminiz basariyla gerceklesti,Tesekkur ederiz.\t\n");
			printf("Yeni bakiyeniz:%.2f\n",bakiye);	
	
		}
		
	}
		
	
	else{
		printf("Yanlis secim yaptiniz.");
		printf("Bizi tercih ettiginiz icin tesekkur ederiz,iyi gunler.");
	}
}
