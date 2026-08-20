int main(){
    char str [20];
    char keyword [][20]={"int","float","double","char","if","else","for","while","do","switch","case","break","continue","return"};
    int i,found=0;
    printf("Enter a string: ");
    scanf("%s",str);
    for(i=0;i<14;i++){
        if(strcmp(str,keyword[i])==0){
            found=1;
            break;
        }
    }
    if(found==1){
        printf("The entered string is a keyword.\n");
    }
    else{
        printf("The entered string is not a keyword.\n");
    }
    return 0;
}