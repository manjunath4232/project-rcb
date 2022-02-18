#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Data_size 100

   
            else
            {   
                int current_vehicle = O[i].num_vehicles;
                //added to vehicles entry of owner
                O[i].Total_vehicles[current_vehicle].Owners_ID = id;
                printf("Enter Registration number of Vehicle: ");
                scanf("%s", O[i].Total_vehicles[current_vehicle].registration_no);
                printf("Enter Type of Vehicle: ");
                scanf("%s", O[i].Total_vehicles[current_vehicle].vehicle_type);
                printf("Enter Vehicle Maker: ");
                scanf("%s", O[i].Total_vehicles[current_vehicle].maker);
                printf("Enter Engine number of Vehicle: ");
                scanf("%s", O[i].Total_vehicles[current_vehicle].engine_no);
                printf("Enter Year of manufacture: ");
                scanf("%d", &O[i].Total_vehicles[current_vehicle].mf_year);
                printf("error here");
                printf("Enter Price of Vehicle: ");
                scanf("%d", &O[i].Total_vehicles[current_vehicle].price);

                //added to remaining owner properties
                printf("Enter Date(dd) of purchased Vehicle: ");
                scanf("%d", &O[i].purchase_date[current_vehicle]);
                printf("Enter Month(mm) of purchased Vehicle: ");
                scanf("%d", &O[i].purchase_month[current_vehicle]);
                printf("Enter Year(yy) of purchased Vehicle: ");
                scanf("%d", &O[i].purchase_year[current_vehicle]);
                O[i].purchase_amount[current_vehicle] = O[i].Total_vehicles[current_vehicle].price;
                O[i].num_vehicles++;
                f=0;
                printf("Vehicle added with id %s to owner %s  successfully \n", O[i].Total_vehicles[current_vehicle].registration_no, O[i].Owner_name);
            }
        }
    }
    if(f==1)
    {
        printf("No users Found with given ID");
    }
    return f;
}//End of second Question
//Start of third Question
int Delete_Vehicle(struct Owner * O, int * current_owner)
{
    int id, i, j;
    printf("Enter ID of Owner: ");
    scanf("%d", &id);

    for(i=0;i<Data_size;i++)
    {
        if(O[i].Owners_ID == id)
        {
            char Vehicle_ID[20];
            printf("Enter Registration number of Vehicle: ");
            scanf("%s", &Vehicle_ID);

            for(j=0;j<O[i].num_vehicles;j++)
            {
                if(O[i].Total_vehicles[j].registration_no==Vehicle_ID)
                {
                    while(j<O[i].num_vehicles-1)
                    {
                        O[i].Total_vehicles[j]=O[i].Total_vehicles[j+1];
                        j++;
                    }
                    printf("Vehicle with registration ID %s Deleted Successfully \n", Vehicle_ID);
                    j++;
                }
            }
            O[i].num_vehicles--;
            if(O[i].num_vehicles==0)
            {
                while(i<*current_owner-1)
                {
                    O[i]=O[i+1];
                    i++;   
                }
                *current_owner--;
                i++;
                printf("The data has been deleted as the Owner not having any cars left.\n");
            }
        }
    }
    return 0;
}//End of third question
//Start of fourth question
void swap(struct Vehicle *a, struct Vehicle *b)
{
    struct Vehicle t = *a;
    *a = *b;
    *b = t;
}

void sort_by_mfdate(struct Owner * O, int current_owner)
{
    int id, i, j, k;
    printf("Enter ID of Owner: ");
    scanf("%d", &id);

    for(i=0; i<current_owner; i++)
    {
        if(O[i].Owners_ID==id)
        {
            for(j=0; j<O[i].num_vehicles-1; j++)
            {
                for(k=0; k<O[i].num_vehicles-1; k++)
                {
                    if(O[i].Total_vehicles[j].mf_year>O[i].Total_vehicles[k].mf_year)
                    {
                        swap(&O[i].Total_vehicles[j], &O[i].Total_vehicles[k]);
                    }
                }
            }
        }
    }
}//End of fourth question
//Start of fifth question
void Dlt_less_1990(struct Owner * O, int * current_owner)
{
    int i,j;
    for(i=0; i<*current_owner; i++)
    {
        for(j=0; j<O[i].num_vehicles;j++)
        {
            if(O[i].Total_vehicles[j].mf_year<1990)
            {
                int c=j;
                while(c<O[i].num_vehicles-1)
                {
                    O[i].Total_vehicles[j]=O[i].Total_vehicles[j+1];
                    c++;
                }
                printf("The Vehicle is Deleted as it is manufactured before 1990.\n");
                O[i].num_vehicles--;
            }
        }
        if(O[i].num_vehicles==0)
        {
            int d=i;
            while(d<*current_owner-1)
            {
                O[d]=O[d+1];
                d++;
            }
            *current_owner--;
            printf("Owner had no cars left in data, hence removed\n");
        }
    }
}//End of fifth question
//Start of sixth question
void max_and_second_max(struct Owner * O, int current_size)
{
    int i, m1, m2;
    m1=m2=O[0].num_vehicles;
    for(i=0; i<current_size;i++)
    {
        if(O[i].num_vehicles>m1)
        {
            m2=m1;
            m1=O[i].num_vehicles;
        }
        else if(O[i].num_vehicles>m2 && O[i].num_vehicles<m1)
        {
            m2=O[i].num_vehicles;
        }
    }
    int j;
    for(j=0; j<current_size; j++)
    {
        if(O[j].num_vehicles==m1)
        {
            printf("Owner with ID %d has maximum number of cars",  O[j].Owners_ID);
        }
        else if(O[j].num_vehicles==m2)
        {
            printf("Owner with ID %d has second maximum number of cars",  O[j].Owners_ID);
        }
    }
}//End of sixth question
//Start of seventh question
void check_two_wheeler(struct Owner * O, int current_size)
{
    int i, count, j;
    for(i=0; i<current_size;i++)
    {   
        count=0;
        for(j=0;j<O[i].num_vehicles;j++)
        {
            if(toupper(O[i].Total_vehicles[j].vehicle_type) == "2-WHEELER")
            {
                count++;
            }
        }
        if(count>1)
        {
            printf("Owner with ID %d had purchased more than 1, 2-wheelers in the same year",  O[i].Owners_ID);
        }
    }
}//End  seventh question
//Start  eigth question
void find_max_cost(struct Owner * O, int current_size)
{
    int Owner_ID,i,choice,f;
    char Owner_Name[20];
    printf("Enter Name(1) or ID(2) of the owner: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            f=1;
            break;
        case 2:
            f=2;
            break;
        default:
            f=0;
            printf("Invalid input");
    }
    if(f==1)
    {
        printf("Enter name of the Owner: ");
        scanf("%s", &Owner_Name);
        int verify=0;
        for(i=0; i<current_size; i++)
        {
            if(toupper(O[i].Owner_name)==toupper(Owner_Name))
            {
                int max = O[i].purchase_amount[0];
                int j,this_vehicle=0;
                for(j=0; j<O[i].num_vehicles; j++)
                {
                    if(O[i].purchase_amount[j]>max)
                    {
                        max = O[i].purchase_amount[j];
                        this_vehicle=j;
                    }
                }
                verify=1;
                printf("%s has the costliest vehicle with registration number %s which costs %d\n",O[i].Owner_name,O[i].Total_vehicles[this_vehicle].registration_no, max);
            }
        }
        if(verify==0)
        {
            printf("The given name of Owner does not exist\n");
        }
    }
    if(f==2)
    {
        printf("Enter ID of the Owner: ");
        scanf("%d", &Owner_ID);
        int verify=0;
        for(i=0; i<current_size; i++)
        {
            if(O[i].Owners_ID==Owner_ID)
            {
                int max = O[i].purchase_amount[0];
                int j,this_vehicle=0;
                for(j=0; j<O[i].num_vehicles; j++)
                {
                    if(O[i].purchase_amount[j]>max)
                    {
                        max = O[i].purchase_amount[j];
                        this_vehicle=j;
                    }
                }
                verify=1;
                printf("%d has the costliest vehicle with registration number %s which costs %d\n",O[i].Owners_ID,O[i].Total_vehicles[this_vehicle].registration_no, max);
            }
        }
        if(verify==0)
        {
            printf("The given ID of Owner does not exist\n");
        }
    }
}//End of eighth question
//Start of ninth question
void check_by_brand(struct Owner * O, int current_size)
{
    char brand[20];
    printf("Enter brand of the vehicle: ");
    scanf("%s", &brand);
    int i,j;
    for(i=0; i<current_size; i++)
    {
        int v_counter=0;
        for(j=0; j<O[i].num_vehicles; j++)
        {
            if(toupper(O[i].Total_vehicles[j].maker)==toupper(brand))
            {
                v_counter++;
            }
        }
        if(v_counter>1)
        {
            printf("%s owns more than one car of brand chosen %s\n", O[i].Owner_name, brand);
        }
    }
}//End  ninth Question
//Start  tenth Question
void check_type_by_year(struct Owner * O, int current_size)
{
    int year;
    printf("Enter the purchased year: ");
    scanf("%d", &year);
    int i,j;
    for(i=0; i<current_size; i++)
    {
        int v_counter=0;
        for(j=0; j<O[i].num_vehicles; j++)
        {
            if(O[i].purchase_year[j]==year && toupper(O[i].Total_vehicles[j].vehicle_type)=="3-WHEELER")
            {
                v_counter++;
            }
        }
        if(v_counter>0)
        {
            printf("%s had purchased 3-wheeler in the given year %d\n",O[i].Owner_name, year);
        }
    }
}//End  tenth Question
int main()
{
    int owner_counter=0;
    struct Owner Owner_Data[Data_size];

    int choice;
    int repeat;
    do
    {
        printf("1)Add new Owner\n");
        printf("2)Add new Vehicle to the owner\n");
        printf("3)Delete a Vehicle \n");
        printf("4)+List of cars of a owner in ascending order which are sorted by year of manufacture\n");
        printf("5)Delete all vehicles manufactured before 1990 from the database\n");
        printf("6)Find Owner with maximum and second maximum number of vehicles\n");
        printf("7)Find Owners who purchased  more than 1, 2-wheelers in the same year\n");
        printf("8)Find out the price of the costliest vehicle owned by the Owner entered by the user\n");
        printf("9)Find out the Owners who owns more than one vehicle of the brand chosen by the user\n");
        printf("10)List the owners who purchased 3-wheeler in the year provided by the user\n");
        printf("Enter the operation number that you want to do: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_owner(Owner_Data, &owner_counter);
                break;
            case 2:
                int Add_Vehicle(Owner_Data);
                break;
            case 3:
                Delete_Vehicle(Owner_Data, &owner_counter);
                break;
            case 4:
                sort_by_mfdate(Owner_Data, owner_counter);
                break;
            case 5:
                Dlt_less_1990(Owner_Data, &owner_counter);
                break;
            case 6:
                max_and_second_max(Owner_Data, owner_counter);
                break;
            case 7:
                check_two_wheeler(Owner_Data, owner_counter);
                break;
            case 8:
                find_max_cost(Owner_Data, owner_counter);
                break;
            case 9:
                check_by_brand(Owner_Data, owner_counter);
                break;
            case 10:
                check_type_by_year(Owner_Data, owner_counter);
            default:
                printf("Invalid input \n");
        }

        printf("Do you want to Continue(If Yes-Enter 1,Else Enter-0): ");
        scanf("%d", &repeat);
    }while(repeat);
}
