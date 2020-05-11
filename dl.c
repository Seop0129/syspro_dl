#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>

int main(void)

{

        char * cwd = (char *)malloc(sizeof(char) * 1024);

        DIR * dir_info = NULL;

        struct dirent * entry = NULL;



        getcwd(cwd, 1024); //작업 디렉토리의 전체 이름을 cwd에 받아옵니다



        if( (dir_info = opendir(cwd)) == NULL) //디렉토리를 열었을때 안에 아무것도 없다면 밑의 글을 출력 합니다

        {

                printf("current directory error\n");

                exit(1);

        }



        while( (entry = readdir(dir_info)) != NULL) //연 디렉토리에 파일과 디렉토리를 호출하여 출력합니다(더 이상 파일이나 디렉토리가 없어 NULL을 반환할때까지)

        {

                printf("%s\n", entry->d_name);

        }



        free(cwd); //malloc()에서 할당받은 메모리를 시스템에 반환합니다
	cwd = NULL;

        closedir(dir_info); //연 디렉토리를 닫아 줍니다



        return 0;

	/* forum.falinux.com에서 getcwd, opendir, readdir, free, closedir들을 참고 했습니다*/

}
