# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// int main()
// {
//     char *a = "ouiamnaoulad el haj\n123\n4567\n890";
//     char *b = "\n";
//     printf("%zu\n", ft_strlen(a));
// }
int main(void)
{
    int fd;
    //char *line;
	char *buff = malloc(50);
    fd = open("ouiam.txt", O_RDONLY); 

    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("%s\n", line);
    //     free(line);
    // }
	read(fd , buff, 50);
    printf("%s\n", buff);
    //system("leaks a.out");

    close(fd);

    return 0;
}


	// printf("%d\n", n);

	// printf("%s\n", buff);

	// printf("++++++++++++++++++++++++++++++++\n");
        // printf("%s\n", str_big);
        // printf("--------------------------------\n");



	// printf("%d\n", p);
    // printf("--------------\n");
    // printf("%s", line);
    // printf("--------------\n");
    // printf("%s\n", str_mini);
    // printf("--------------\n");
    // printf("%s", str_big);