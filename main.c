#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct voiture{
	int idVoiture;
	char marque[15];
	char nomVoiture[15];
	char couleur[7];
	int nbplaces;
	int prixJour;
	char EnLocation[4];
}voiture;
typedef struct{
	int j,m,A;
}date;
typedef struct contraLocation{
	float numContrat;
	int idVoiture;
	int idClient;
	date debut;
	date fin;
	int cout;
}contrat;
typedef struct Client{
	int idClient;
	char nom[20];
	char prenom[20];
	int cin;
	char adresse[15];
	int telephone;
}Client;
void MenuP();
void MenuV();
void MenuC();
void MenuL();
void ListeV();
void ListeC();
void Liste_contrat();
void ajouterV();
void ajouterC();
void ajouter_Contrat();
int Prix(contrat);
void supprimer(char);
void Mode(char);
int rechV(int id);
int rechC(int);
void rout();
main(){
    FILE *V,*C,*Co;
       V=fopen("Voitures.txt","a+");
           if(V==NULL)
              {
                printf("\n Erreure d'ouverture !");
                exit(1);          
                }
       fclose(V);
       C=fopen("Clients.txt","a+");
           if(C==NULL)
              {
                printf("\n Erreure d'ouverture !");
                exit(1);         
                }
       fclose(C);
       Co=fopen("ContratsLocations.txt","a+");
           if(Co==NULL)
              {
                printf("\n Erreure d'ouverture !");
                exit(1); 
                }
       fclose(Co);
    while(1) MenuP();

}
void MenuP(){
	int n;
	do{
		printf("\n");
		printf("\n");
		printf("                                 Menu principal            \n");
	printf("                         Location...........................1\n");
	printf("                         Gestion voiteur....................2\n");
	printf("                         Gestion client.....................3\n");
	printf("                         Quitter............................4\n");
	printf("\n");
	printf("                         votre choix ");
	scanf("%d",&n);
	system("cls");
	switch(n){
	   	case 1: MenuL();  
         break;
	  	case 2: MenuV();
	   	 break;
     	case 3: MenuC();
       	 break;
	   	case 4: exit(1); 
    	 break;
			}
	}while(1);
}
void MenuV(){
	int N;
	printf("\n");
	printf("\n");
	 printf("                                    Gestion des voitures \n");
     printf("                         Liste des voitures.......................1\n");
	 printf("                         ajouter voiture..........................2\n");
	 printf("                         Modifier voiture.........................3\n");
	 printf("                         supprimer voiture........................4\n");
	 printf("                         Retour...................................5\n");
	 printf("\n");
	 printf("                         votre choix");
	 scanf("%d",&N);
	 system("cls");
	 switch(N){
	     case 1:ListeV();  
		  break;
	     case 2:ajouterV();
	      break;
	     case 3:Mode('V');
	     printf("\n");
	     printf("                       liste du Voiture   ");
		        ListeV();
	      break;
	     case 4:supprimer('V');
	     printf("\n");
	     printf("                       liste du Voiture   ");
		        ListeV(); 
	      break;
		 case 5:MenuP();
		  break;
			}
}
void MenuC(){
	int N;
	printf("\n");
	printf("\n");
	printf("                             Gestion des clientn \n");
	printf("                   Liste des client.......................1\n");
	printf("                   ajouter client..........................2\n");
	printf("                   Modifier client.........................3\n");
	printf("                   supprimer client........................4\n");
	printf("                   Retour...................................5\n");
	printf("\n");
	printf("                   votre choix ");
	scanf("%d",&N);
	system("cls");
	switch(N){
	    case 1:ListeC(); 
		  break;
	    case 2:ajouterC();
	      break;
	    case 3:Mode('C');
	      printf("\n");
	      printf("                List du Clients :");
	      ListeC();
	      break;
	    case 4:printf("\n");
	      printf("                List du Clients :");
	      ListeC();
		supprimer('C');
	    printf("\n");
	    printf("\n");
	      printf("                List du Clients :");
	      ListeC();
	      break;
	    case 5:MenuP();	
		  break;
	        }
}
void MenuL(){
	int N;
	printf("\n");
	printf("\n");
	printf("                                Location d'une voiture\n");
	printf("                      Visualiser...............................1\n");
	printf("                      Louer voiture............................2\n");
	printf("                      Retourner voiture........................3\n");
	printf("                      Modifier conrat..........................4\n");
	printf("                      Supprimer contrat........................5\n");
	printf("                      Retour...................................6\n");
	printf("\n");
	printf("                      votre choix");
	scanf("%d",&N);
	system("cls");
	switch(N){
	    case 1:Liste_contrat(); 
		  break;
	    case 2:ajouter_Contrat();
	      break;
	    case 3:rout();
	      break;
	    case 4:;
	      break;
	    case 5:;
	      break;
	    case 6: MenuP();
	        }
}
void ListeV(){
	FILE *F;
	char c;
	F=fopen("Voitures.txt","r");
	c=fgetc(F);
	printf("\n");
	printf("\n");
	printf(" idVoiture | marque | nomVoiture | couleur | nbplaces | prixJour | EnLocation \n");
	while(c!= EOF ){
		printf("%c",c);
		c=fgetc(F);
	}
	fclose(F);
}
void ListeC(){
	FILE *F;
	char c;
	F=fopen("Clients.txt","r");
	c=fgetc(F);
	printf("\n");
	printf("\n");
	printf("   idClient | nom | prenom | cin | adresse | telephone \n");
	while(c!= EOF ){
		printf("%c",c);
		c=fgetc(F);
	}
	fclose(F);
}
void Liste_contrat(){
	FILE *F;
	F=fopen("ContratsLocations.txt","r");
	char c=fgetc(F);
	printf("numéro Contrat | id Voiture | id Client  | date debut||\n");
	while(c!= EOF ){
		printf("%c",c);
		c=fgetc(F);
	}
	fclose(F);
}
void ajouterV(){
	FILE *ptv;
	int nbv;
	voiture *tab,*pt;
	printf("Veuillez entrer le nombre des voitures que vous veri ajouter : ");
	scanf("%d",&nbv);
	tab=(voiture*)malloc(nbv*sizeof(voiture));
	for(pt=tab;pt<tab+nbv;pt++){
		printf("Veuillez entrer le id de voiture %d                : ",pt-tab+1);
		scanf("%d",&pt->idVoiture);
		fflush(stdin);
		printf("Veuillez entrer la marque de voiture %d            : ",pt-tab+1);
		scanf("%s",&pt->marque);
		fflush(stdin);
		printf("Veuillez entrer le nom de voiture %d               : ",pt-tab+1);
		scanf("%s",&pt->nomVoiture);
		fflush(stdin);
		printf("Veuillez entrer la couleur de voiture %d           : ",pt-tab+1);
		scanf("%s",&pt->couleur);
		fflush(stdin);
		printf("Veuillez entrer le nombre de place de voiture %d   : ",pt-tab+1);
		scanf("%d",&pt->nbplaces);
		fflush(stdin);
		printf("Veuillez entrer le prix par jour de voiture %d     : ",pt-tab+1);
		scanf("%d",&pt->prixJour);
		fflush(stdin);
		printf("La voiture %d est enlocation? oui/non              : ",pt-tab+1);
		scanf("%s",&pt->EnLocation);
		fflush(stdin);
		printf("\n");
	}
	ptv=fopen("voitures.txt","a+");
	for(pt=tab;pt<tab+nbv;pt++){
		fprintf(ptv,"\n    %d     %s      %s     %s      %d       %d      %s",pt->idVoiture,pt->marque,pt->nomVoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->EnLocation);
	}
	free(tab);
	fclose(ptv);
}
void ajouterC(){
	FILE *file;
	int N,i;
	file=fopen("Clients.txt","a+");
	Client C;
	printf("    entrez nb de clients ");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("    id du Client %d : ",i+1);
		scanf("%d",&C.idClient);
		printf("    nom  du Client %d : ",i+1);
		scanf("%s",&C.nom);
		printf("    prenom  du Client %d : ",i+1);
		scanf("%s",&C.prenom);
		printf("    CIN du Client %d : ",i+1);
		scanf("%d",&C.cin);
		printf("    adresse du Client %d: ",i+1);
		scanf("%s",&C.adresse);
		printf("    telephone du Client %d : ",i+1);
		scanf("%d",&C.telephone);
		fprintf(file,"%d %s %s %d %s %d\n",C.idClient,C.nom,C.prenom,C.cin,C.adresse,C.telephone);
	}
	fclose(file);
}
void ajouter_Contrat(){
	FILE *F;
	contrat Co;
	int n,i,h,H;
	printf("nb contrat ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++){
		printf(" num contrat :");
		scanf("%f",&Co.numContrat);
		printf(" id voiture :");
		scanf("%d",&Co.idVoiture);
		h=rechV(Co.idVoiture);
		if(h==0){
			printf(" id client :");
			scanf("%d",&Co.idClient);
			H=rechV(Co.idClient);
			if(H==0){
				printf(" debut :");
				scanf("%d%d%d",&Co.debut.j,&Co.debut.m,&Co.debut.A);
				printf(" fin :");
				scanf("%d%d%d",&Co.fin.j,&Co.fin.m,&Co.fin.A);
				Co.cout=Prix(Co);
				F=fopen("ContratsLocations.txt","a+");
				fprintf(F,"\n %f %d %d %d%d%d %d%d%d %d",Co.numContrat,Co.idVoiture,Co.idClient,Co.debut.j,Co.debut.m,Co.debut.A,Co.fin.j,Co.fin.m,Co.fin.A,Co.cout);
				fclose(F);
			}
			else{
				printf("ce client n'est pas encoure enregistrer, il faut l'enregistrer . ");
			}
		}
		else if(h==1){
			printf("Cette voiture est louée ");
		}
		else if(h==2){
			printf("la voiture que vous avez entrer n'exist pas ");
		}		
	}
}
int Prix(contrat C){
	FILE *F;
	int P,Ptotal;
	voiture V;
	F=fopen("Voitures.txt","r");
	while(!feof(F)){
		fscanf(F,"%d %s %s %s %d %d %s",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
		if(C.idVoiture==V.idVoiture){
			P=V.prixJour;
		}
	}
	Ptotal=(((C.debut.A)*365+(C.debut.m)*30+C.debut.j)-((C.fin.A)*365+(C.fin.m)*30+C.fin.j))*P;
	fclose(F);
	return Ptotal;
}
void supprimer(char h){
	FILE *tp,*F;
	voiture V;
	Client C;
	int id;
	if(h=='V'){
		printf("\n");
		printf("\n");
		printf("  Entrer le id de voiture a supprimer ");
		scanf("%d",&id);
		tp=fopen("Voitures.txt","r");
	    F=fopen("newV.txt","w");
	    while(!feof(tp)){
			fscanf(tp,"%d %s %s %s %d %d %s",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
			if(id!=V.idVoiture){
				fprintf(F,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
		}
		}
		fclose(tp);
		remove("Voitures.txt");
		fclose(F);
		rename("newV.txt","voitures.txt");
	}
	if(h=='C'){
		printf("\n");
		printf("\n");
		printf("Veuillez entrer le id du client a supprimer :");
		scanf("%d",&id);
		tp=fopen("Clients.txt","r");
		F=fopen("newC.txt","a+");
		while(!feof(tp)){
			fscanf(tp,"%d %s %s %d %s %d",&C.idClient,&C.nom,&C.prenom,&C.cin,&C.adresse,&C.telephone);
			if(id!=C.idClient){
				fprintf(F,"%d %s %s %d %s %d",C.idClient,C.nom,C.prenom,C.cin,C.adresse,C.telephone);
			}
		}
		fclose(tp);
		fclose(F);
		remove("Clients.txt");
		rename("newC.txt","Clients.txt");
	}
}
void Mode(char h){
	FILE *F,*pt;
	voiture V;
	Client C;
	int id;
	if(h='V'){
		printf("  Entrer le id de voiture a modifier :");
		scanf("%d",&id);
		pt=fopen("voitures.txt","r");
		F=fopen("newV.txt","w");
		while(!feof(pt)){
			fscanf(pt,"%d %s %s %s %d %d %s",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
			if(id!=V.idVoiture){
				fprintf(F,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
			}
		    if(id==V.idVoiture){
				printf("   id voiture : ");
				scanf("%d",&V.idVoiture);
				printf("   Marque : ");
				scanf("%s",&V.marque);
				printf("   nom de voiture : ");
				scanf("%s",&V.nomVoiture);
				printf("   couleur  : ");
				scanf("%s",&V.couleur);
				printf("   nb de places : ");
				scanf("%d",&V.nbplaces);
				printf("   prixjour : ");
				scanf("%d",&V.prixJour);
				printf("   EnLocation : ");
				scanf("%s",&V.EnLocation);
				fprintf(F,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
			}
		}
		fclose(pt);
		fclose(F);
		remove("voitures.txt");
		rename("newV.txt","voitures.txt");
	}
    if(h='C'){
		printf("\n");
		printf("   Enrer le id de client a modifier :");
		scanf("%d",&id);
		printf("\n");
		pt=fopen("Clients.txt","r");
		F=fopen("newC.txt","a+");
		while(!feof(pt)){
			fscanf(pt,"%d %s %s %d %s %d ",&C.idClient,&C.nom,&C.prenom,&C.cin,&C.adresse,&C.telephone);
			if(id!=C.idClient){
				fprintf(F,"%d %s %s %d %s %d\n",C.idClient,C.nom,C.prenom,C.cin,C.adresse,C.telephone);
			}
			else if(id==C.idClient){
				printf("    id Client : ");
				scanf("%d",&C.idClient);
				printf("    nom : ");
				scanf("%s",&C.nom);
				printf("    prenom : ");
				scanf("%s",&C.prenom);
				printf("    CIN  : ");
				scanf("%d",&C.cin);
				printf("    adresse : ");
				scanf("%s",&C.adresse);
				printf("    telephone : ");
				scanf("%d",&C.telephone);
				fprintf(F,"%d %s %s %d %s %d\n ",C.idClient,C.nom,C.prenom,C.cin,C.adresse,C.telephone);
			}
		}
		fclose(F);
		fclose(pt);
		remove("Clients.txt");
		rename("newC.txt","Clients.txt");
	}
}
int rechV(int id){
	FILE *F;
	voiture V;
	char ch[3]="non";
	F=fopen("Voitures.txt","r");
	while(!feof(F)){
		fscanf(F,"%d %s %s %s %d %d %s",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
			if(id==V.idVoiture){
				if(strcmp(V.EnLocation,ch)==0){
					return 0;
				}
				else{
					return 1;
				}
			}
		}
				return 2;
	fclose(F);
}
int rechC(int id){
	FILE *F;
	Client C;
	F=fopen("Clients.txt","r");
	while(!feof(F)){
		fscanf(F,"%d %s %s %d %s %d",&C.idClient,&C.nom,&C.prenom,&C.cin,&C.adresse,&C.telephone);
		if(id==C.idClient){
			return 0;
		}
	}
		return 1;
	
	fclose(F);
}
void rout(){
	FILE *F,*pt;
	int id;
	char ch[3]="oui";
	voiture V;
	printf("id de voiture :");
	scanf("%d",&id);
	pt=fopen("voitures.txt","r");
	F=fopen("newV.txt","w");
	while(!feof(pt)){
		fscanf(pt,"%d %s %s %s %d %d %s",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
		if(id!=V.idVoiture){
			fprintf(F,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
			}
		else if(id==V.idVoiture){
			fprintf(F,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,ch);
			}
	}
	fclose(pt);
	remove("Voitures.txt");
	fclose(F);
	rename("newV.txt","voitures.txt");
}
void Mode_contrat(){
	 FILE *F,*tp;
	 int h,H;
	 float nc;
	 contrat Co,Cn;
	 printf("saisir num contrat :");
	 scanf("%f",&nc);
	 F=fopen("ContratsLocations.txt","r");
	 tp=fopen("NewContra.txt","a+");
	 while(!feof(F)){
	 	fscanf(F,"%f %d %d %d %d %d %d %d %d %d",&Co.numContrat,&Co.idVoiture,&Co.idClient,&Co.debut.j,&Co.debut.m,&Co.debut.A,&Co.fin.j,&Co.fin.m,&Co.fin.A,&Co.cout);
	 	if(nc!=Co.numContrat){
	 		fprintf(tp,"\n %f %d %d %d%d%d %d%d%d %d",Co.numContrat,Co.idVoiture,Co.idClient,Co.debut.j,Co.debut.m,Co.debut.A,Co.fin.j,Co.fin.m,Co.fin.A,Co.cout);
		 }
		else if(nc==Co.numContrat){
		  printf("num contrat :");
		  scanf("%f",&Cn.numContrat);
		  printf("id voiture :");
		  scanf("%d",&Cn.idVoiture);
		  h=rechV(Cn.idVoiture);
		  if(h==0){
			printf("id client :");
			scanf("%d",&Cn.idClient);
			H=rechV(Cn.idClient);
			if(H==0){
				printf("debut :");
				scanf("%d%d%d",&Cn.debut.j,&Cn.debut.m,&Cn.debut.A);
				printf("fin :");
				scanf("%d%d%d",&Cn.fin.j,&Cn.fin.m,&Cn.fin.A);
				Co.cout=Prix(Cn);
				fprintf(tp,"\n %f %d %d %d%d%d %d%d%d %d",Cn.numContrat,Cn.idVoiture,Cn.idClient,Cn.debut.j,Cn.debut.m,Cn.debut.A,Cn.fin.j,Cn.fin.m,Cn.fin.A,Cn.cout);
				if(Co.idVoiture!=Cn.idVoiture){
				  FILE *L,*T;
	              char ch[3]="oui";
	              voiture V;
	              L=fopen("voitures.txt","r");
	              T=fopen("newV.txt","w");
	              while(!feof(L)){
		            fscanf(L,"%d %s %s %s %d %d %s",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
		            if(Co.idVoiture!=V.idVoiture){
			          fprintf(T,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
			        }
		            else if(Co.idVoiture==V.idVoiture){
			            fprintf(T,"\n %d %s %s %s %d %d %s",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,ch);
			        }
		         }
		         fclose(L);
		         remove("Voitures.txt");
		         fclose(T);
		         rename("newV.txt","voitures.txt");
			  }
			}
			else{
				printf("ce client n'est pas encoure enregistrer, il faut l'enregistrer . ");
				fclose(tp);
		        remove("NewContra.txt");
		        fclose(F);
			}
		}
		else if(h==1){
			printf("Cette voiture est louée ");
			close(tp);
		    remove("NewContra.txt");
		    fclose(F);
		}
		else if(h==2){
			printf("la voiture que vous avez entrer n'exist pas ");
			close(tp);
		    remove("NewContra.txt");
		    fclose(F);
		}	
		}
	 }
	 fclose(F);
	 remove("ContratsLocations.txt");
	 fclose(tp);
	 rename("NewContra.txt","ContratsLocations.txt");
}
void supC(){	
}
