#include<stdio.h>
#include<string.h>
struct student{
    char fname[20];
    int rollno;
};
struct semester{
    char subcode[6];
    int marks;
    char grade;
    int gp;
};
struct marksheet{
    struct semester sem1[4];
    struct semester sem2[4];
    struct student name;
    float sgpa1;
    float sgpa2;
    float cgpa;
};
char Grade(int mks){
    if(mks>=90)
        return 'O';
    else if(mks>=80)
        return 'A';
    else if(mks>=70)
        return 'B';
    else if(mks>=60)
        return 'C';
    else if(mks>=50)
        return 'D';
    else if(mks>=40)
        return 'E';
    else
        return 'F';
}
int GradePoint(char grade){
    switch(grade){
        case 'O':
        return 10;
        case 'A':
        return 9;
        case 'B':
        return 8;
        case 'C':
        return 7;
        case 'D':
        return 6;
        case 'E':
        return 5;
        default:
        return 0;
    }
}
void Padding(char str[15],int width){
    int padding=(width-strlen(str))/2;
    for(int k=0;k<padding;k++)
            printf(" ");

}
void RevPadding(char str[15],int width){
    int padding=(width-strlen(str))/2;
    int revpadding=padding+strlen(str);
    for(int k=revpadding;k<width;k++)
        printf(" ");
}
void IntPadding(int n,int width){
    int length=0;
    if(n==0)
        length=1;
    while(n>0){
        n/=10;
        length++;
    }
    int padding=(width-length)/2;
    for(int k=0;k<padding;k++)
        printf(" ");
}
void RevIntPadding(int n,int width){
    int length=0;
    if(n==0)
        length=1;
    while(n>0){
        n/=10;
        length++;
    }
    int padding=(width-length)/2;
    int revpadding=(width+length)/2;
    for(int k=revpadding;k<width;k++)
        printf(" ");
}

float CalculateSgpa(struct marksheet m[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            m[i].sgpa1+=(m[i].sem1[j].gp*4)/16;
        }
        for(int j=0;j<4;j++){
            m[i].sgpa2+=(m[i].sem2[j].gp*4)/16;
        }
        
    }
}
float CalculateCgpa(struct marksheet m[],int n){
    for(int i=0;i<n;i++){
        m[i].cgpa=(m[i].sgpa1+m[i].sgpa2)/2;
    }
}
void DisplayStudentDetails(struct marksheet m[],int n){
    int i,j,k,len,padding;
    for(i=0;i<n;i++){
        printf("\nName:%s",m[i].name.fname);
        printf("\nRoll No.:%d\n",m[i].name.rollno);
        Padding("Marsheet",120);
        printf("Marksheet\n");
        Padding("Semester 1",60);
        printf("Semester 1");
        RevPadding("Semester 1",60);
        Padding("Semester 2",60);
        printf("Semester 2\n");
        for(int k=0;k<2;k++){
            Padding("Subject Code",15);
            printf("Subject Code");
            RevPadding("Subject Code",15);
            Padding("Marks",15);
            printf("Marks");
            RevPadding("Marks",15);
            Padding("Grade",15);
            printf("Grade");
            RevPadding("Grade",15);
            Padding("Grade Point",15);
            printf("Grade Point");
            RevPadding("Grade Point",15);
            if(k==0)
                printf("|");
        }
        for(j=0;j<4;j++){
            printf("\n");
            Padding(m[i].sem1[j].subcode,15);
            printf("%s",m[i].sem1[j].subcode);
            RevPadding(m[i].sem1[j].subcode,15);
            IntPadding(m[i].sem1[j].marks,15);
            printf("%d",m[i].sem1[j].marks);
            RevIntPadding(m[i].sem1[j].marks,15);
            Padding(" ",15);
            printf("%c",m[i].sem1[j].grade);
            RevPadding(" ",15);
            IntPadding(m[i].sem1[j].gp,15);
            printf("%d",m[i].sem1[j].gp);
            RevIntPadding(m[i].sem1[j].gp,15);
            printf("|");
            Padding(m[i].sem2[j].subcode,15);
            printf("%s",m[i].sem2[j].subcode);
            RevPadding(m[i].sem2[j].subcode,15);
            IntPadding(m[i].sem2[j].marks,15);
            printf("%d",m[i].sem2[j].marks);
            RevIntPadding(m[i].sem2[j].marks,15);
            Padding(" ",15);
            printf("%c",m[i].sem2[j].grade);
            RevPadding(" ",15);
            IntPadding(m[i].sem2[j].gp,15);
            printf("%d",m[i].sem2[j].gp);
            RevIntPadding(m[i].sem2[j].gp,15);
        }
        printf("\n");
        CalculateSgpa(m,n);
        CalculateCgpa(m,n);
        printf("SGPA=%-55.2f",m[i].sgpa1);
        printf("|");
        printf("SGPA=%-55.2f",m[i].sgpa2);
        printf("\n");
        printf("CGPA=%-55.2f",m[i].cgpa);
    }
}
int main(){
    int n,i,j;
    printf("Enter the number of students:");
    scanf("%d",&n);
    struct marksheet m1[n];
    for(i=0;i<n;i++){
        getchar();
        printf("\nEnter your name:");
        gets(m1[i].name.fname); 
        printf("Enter your roll number:");
        scanf("%d",&m1[i].name.rollno);
        printf("\nEnter the Details of Semester 1\n");
        for(j=0;j<4;j++){
            printf("\nEnter the subject code:");
            scanf("%s",&m1[i].sem1[j].subcode);
            do{
                printf("Enter the marks out of 100:");
                scanf("%d",&m1[i].sem1[j].marks);
            }while(m1[i].sem1[j].marks>100 || m1[i].sem1[j].marks<0);
            m1[i].sem1[j].grade=Grade(m1[i].sem1[j].marks);
            m1[i].sem1[j].gp=GradePoint(m1[i].sem1[j].grade);
        }
        printf("\nDetails of Semester 2\n");
        for(j=0;j<4;j++){
            printf("\nEnter the subject code:");
            scanf("%s",&m1[i].sem2[j].subcode);
            do{
                printf("Enter the marks out of 100:");
                scanf("%d",&m1[i].sem2[j].marks);
            }while(m1[i].sem2[j].marks>100 || m1[i].sem2[j].marks<0);
            m1[i].sem2[j].grade=Grade(m1[i].sem2[j].marks);
            m1[i].sem2[j].gp=GradePoint(m1[i].sem2[j].grade);
        }
    }
    DisplayStudentDetails(m1,n);
}