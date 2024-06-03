#include<stdio.h> 

#include<string.h> 

#include<stdlib.h> 

struct entry 

{ 

  char name[30]; 

  char gender[10]; 

  int number; 

  char BuildingName[20]; 

  int FlatNo; 

  int VehicleNo; 

  char reason[100]; 

}r; 

void begin(); 

void strt(); 

void user(); 

void add(); 

void search(); 

void del(); 

void display(); 

void update(); 

void multiple_add(); 

void begin() 

{ 

    int ch; 

    printf("\n\n\t\t1.ADMIN"); 

    printf("\n\n\t\t2.USER"); 

    printf("\n\n\t\t"); 

    printf("\n\n\t\tEnter your choice : "); 

    scanf("%d",&ch); 

    if(ch==1) 

    { 

        char a[]="abc@123"; 

        char x[10]; 

        int pin=1234,password; 

        printf("\n\n\t\tEnter Your Username : "); 

        scanf("%s",x); 

        printf("\n\n\t\tEnter Your Password : "); 

        scanf("%d",&password); 

        if(a==x || pin==password) 

        { 

           strt(); 

        } 

        else 

        { 

            printf("\n\n\t\tINCORRECT USERNAME/PASSWORD ENTERED"); 

            exit(0); 

        } 

    } 

    else 

    { 

        user(); 

    } 

} 

void main() 

{ 

    begin(); 

    strt(); 

    user(); 

} 

void strt() 

{ 

    int c; 

    printf("\n\n"); 

    printf("\t\tWELCOME TO SECUZONE\t\t"); 

    printf("\n\t------Select One Of The Choices------\n"); 

    printf("1.\tAdd Visitor\n"); 

    printf("2.\tAdd Multiple Visitor\n"); 

    printf("3.\tView All Entries\n"); 

    printf("4.\tSearch Visitor\n"); 

    printf("5.\tDelete all Entries\n"); 

    printf("6.\tUpdate an entry\n"); 

    printf("7.\tExit\n"); 

    printf("\n\n\t\t"); 

    printf("\t\tEnter Your Choice : "); 

    scanf("%d",&c); 

    switch(c) 

    { 

        case 1: 

        add(); 

        break; 

        case 2: 

        multiple_add(); 

        break; 

        case 3: 

        display(); 

        break; 

        case 4: 

        search(); 

        break; 

        case 5: 

        del(); 

        break; 

        case 6: 

        update(); 

        break; 

        case 7: 

        printf("\n\n\t\tThank You for using SECUZONE"); 

        exit(0); 

        break; 

        default: 

        printf("Wrong choice entered.......Please Try Again.....Sorry for the inconvenience"); 

        main(); 

    } 

} 

void add() 

{ 

    FILE*fp; 

    fp=fopen("Record.xlsx","a"); 

    printf("\n\n\t\tName : "); 

    scanf("%s",r.name); 

    printf("\n\n\t\tGender : "); 

    scanf("%s",r.gender); 

    printf("\n\n\t\tContact Number : "); 

    scanf("%d",&r.number); 

    printf("\n\n\t\tBuilding Name : "); 

    scanf("%s",r.BuildingName); 

    printf("\n\n\t\tFlat Number : "); 

    scanf("%d",&r.FlatNo); 

    printf("\n\n\t\tVehicle Number : "); 

    scanf("%d",&r.VehicleNo); 

    printf("\n\n\t\tReason(Mention if its service) : "); 

    scanf("%s",r.reason); 

    fwrite(&r,sizeof(r),1,fp); 

    fclose(fp); 

    printf("\n\n\t\tData Added Successfully"); 

    strt(); 

} 

void display() 

{ 

    FILE*fp1; 

    fp1=fopen("Record.xlsx","r"); 

    printf("\n\tName\t\tGender\t\tContactNo\t\tBuidingName\t\tFlatNo\t\tVehicleNo\t\tReason"); 

    while(fread(&r,sizeof(r),1,fp1)) 

    { 

        printf("\n\t%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\t\t%s\n",r.name,r.gender,r.number,r.BuildingName,r.FlatNo,r.VehicleNo,r.reason); 

    } 

    fclose(fp1); 

    strt(); 

} 

void search() 

{ 

    FILE*fp3; 

    FILE*fp4; 

    int m,q,avl; 

    printf("\n\n\t\tEnter Number of the visitor you want to search :"); 

    scanf("%d",&m); 

    fp3=fopen("Record.xlsx","r"); 

    while(fread(&r,sizeof(r),1,fp3)) 

    { 

        q=r.number; 

        if(q==m) 

        { 

            printf("\n\t\tName : %s",r.name); 

            printf("\n\t\tGender : %s",r.gender); 

            printf("\n\t\tContactNo : %d",r.number); 

            printf("\n\t\tBuidingName : %s",r.BuildingName); 

            printf("\n\t\tFlatNo : %d",r.FlatNo); 

            printf("\n\t\tVehicleNo : %d",r.VehicleNo); 

            printf("\n\t\tReason For Coming : %s",r.reason); 

        } 

    } 

    fclose(fp3); 

    strt(); 

} 

void del() 

{ 

    FILE*fpo; 

    FILE*fpt; 

    int m,avl; 

    int x; 

    char c; 

    printf("\n\n\t\tEnter The number You want to delete : "); 

    scanf("%d",&m); 

    fpo=fopen("Record,xlsx","r"); 

    fpt=fopen("Record.xlsx","w"); 

    while (fread(&r,sizeof(r),1,fpo)) 

    { 

        x=r.number; 

        if(x==m) 

        { 

            fwrite(&r,sizeof(r),1,fpt); 

        } 

    } 

    fclose(fpo); 

    fclose(fpt); 

    strt(); 

    fpo=fopen("Record.xlsx","w"); 

    fpt=fopen("tempfile.xlsx","w"); 

    while(fread(&r,sizeof(r),1,fpt)) 

    { 

        fwrite(&r,sizeof(r),1,fpo); 

    } 

    printf("\n\n\t\tRecord Deleted Successfully"); 

} 

void multiple_add() 

{ 

    int a,i=1; 

    printf("\n\n\t\tEnter Number of visitors : "); 

    scanf("%d",&a); 

    while(i<=a) 

    { 

        FILE*fp; 

        fp=fopen("Record.xlsx","a"); 

        printf("\n\n\t\tName : "); 

        scanf("%s",r.name); 

        printf("\n\n\t\tGender : "); 

        scanf("%s",r.gender); 

        printf("\n\n\t\tContact Number : "); 

        scanf("%d",&r.number); 

        printf("\n\n\t\tBuilding Name : "); 

        scanf("%s",r.BuildingName); 

        printf("\n\n\t\tFlat Number : "); 

        scanf("%d",&r.FlatNo); 

        printf("\n\n\t\tVehicle Number : "); 

        scanf("%d",&r.VehicleNo); 

        printf("\n\n\t\tReason(Mention if its service) : "); 

        scanf("%s",r.reason); 

        fwrite(&r,sizeof(r),1,fp); 

        fclose(fp); 

        printf("\n\n\t\tData Added Successfully"); 

        i++; 

    } 

    strt(); 

} 

void update() 

{ 

    FILE*fpt; 

    FILE*fpo; 

    int x,m,ch; 

    printf("Enter the number which you want to update : "); 

    scanf("%d",&m); 

    fpo=fopen("Record.xlsx","r"); 

    fpt=fopen("TempFile","w"); 

    while(fread(&r,sizeof(r),1,fpo)) 

    { 

        x=r.number; 

        if(x!=m) 

        { 

            fwrite(&r,sizeof(r),1,fpt); 

        } 

        else 

        { 

            printf("\n\n\t\t1. Update Name"); 

            printf("\n\n\t\t2. Update Gender"); 

            printf("\n\n\t\t3. Update BuildingName"); 

            printf("\n\n\t\t4. Update FlatNo"); 

            printf("\n\n\t\t5. Update VehicleNo"); 

            printf("\n\n\t\t6. Update Reason"); 

            printf("\n\n\t\tEnter your choice : "); 

            scanf("%d",&ch); 

            switch(ch) 

            { 

                case 1: 

                printf("Enter name : "); 

                scanf("%s",r.name); 

                break; 

                case 2: 

                printf("Enter Gender : "); 

                scanf("%s",r.gender); 

                break; 

                case 3: 

                printf("Enter BuildingName : "); 

                scanf("%s",r.BuildingName); 

                break; 

                case 4: 

                printf("Enter FlatNo : "); 

                scanf("%d",&r.FlatNo); 

                break; 

                case 5: 

                printf("Enter VehicleNo : "); 

                scanf("%d",&r.VehicleNo); 

                break; 

                case 6: 

                printf("Enter Reason For Arrival : "); 

                scanf("%s",r.reason); 

                break; 

                default: 

                printf("Invalid Selection"); 

                break; 

            } 

            fwrite(&r,sizeof(r),1,fpt); 

        } 

    } 

    fclose(fpo); 

    fclose(fpt); 

    fpo=fopen("Record.xlsx","w"); 

    fpt=fopen("TempFile","r"); 

    while (fread(&r,sizeof(r),1,fpt)) 

    { 

        fwrite(&r,sizeof(r),1,fpo); 

    } 

    fclose(fpo); 

    fclose(fpt); 

    printf("\n\n\t\tRecord Updated\n"); 

} 

void user() 

{ 

    int c; 

    printf("\n\n\t\t=========WELCOME=========="); 

    printf("\n\n\t\t1. Add new visitor"); 

    printf("\n\n\t\t2. Add multiple visitor"); 

    printf("\n\n\t\t3. Update information : "); 

    printf("\n\n\t\t4.Exit"); 

    printf("\n\n\t\tEnter your choice : "); 

    scanf("%d",&c); 

    switch(c) 

    { 

        case 1: 

        add(); 

        break; 

        case 2: 

        multiple_add(); 

        break; 

        case 3: 

        update(); 

        break; 

        case 4: 

        printf("Come Back Soon!!!!!"); 

        exit(0); 

        break; 

        default: 

        printf("Enter valid option pls........."); 

        break; 

    } 

}