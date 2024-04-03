/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:18:26 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:18:29 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	main(void)
{
	char ch;

	//isalpha
	ch = 'A';
	printf("isalpha('A'): original=%d, custom=%d\n", isalpha(ch), ft_isalpha(ch));

	//isdigit
	ch = '5';
	printf("isdigit('5'): original=%d, custom=%d\n", isdigit(ch), ft_isdigit(ch));

    // strlen
    char str[] = "Hello";
    printf("strlen(\"Hello\"): original=%zu, custom=%zu\n", strlen(str), ft_strlen(str));

    // memset
    char arr[5];
    memset(arr, '*', 5);
    printf("memset: original=%s, custom=", arr);
    ft_memset(arr, '*', 5);
    printf("%s\n", arr);

    // bzero (deprecated, use memset instead)
    char arr2[5];
    memset(arr2, 0, 5);
    printf("bzero: original=%s, custom=", arr2);
    ft_bzero(arr2, 5);
    printf("%s\n", arr2);

    // memcpy
    char src[] = "Hello";
    char dest[10];
    memcpy(dest, src, strlen(src) + 1);
    printf("memcpy: original=%s, custom=", dest);
    ft_memcpy(dest, src, strlen(src) + 1);
    printf("%s\n", dest);

    // memmove
    char strs[] = "Hello, world!";
    size_t len = strlen(strs);
    char buffer1[len + 1];
    char buffer2[len + 1];

    // Case where destination overlaps with source using ft_memmove
    ft_memmove(strs + 7, strs, len - 6);
    printf("After ft_memmove: %s\n", strs);

    // Reset str
    strcpy(strs, "Hello, world!");

    // Case where destination overlaps with source using memmove
    memmove(strs + 7, strs, len - 6);
    printf("After memmove: %s\n", strs);

    // toupper, tolower
    char letter = 'a';
    printf("toupper('a'): original=%c, custom=%c\n", toupper(letter), ft_toupper(letter));
    printf("tolower('A'): original=%c, custom=%c\n", tolower(letter), ft_tolower(letter));

    // strchr, strrchr
    char sentence[] = "This is a sample sentence";
    printf("strchr: original=%s, custom=%s\n", strchr(sentence, 's'), ft_strchr(sentence, 's'));
    printf("strrchr: original=%s, custom=%s\n", strrchr(sentence, 's'), ft_strrchr(sentence, 's'));

    // strncmp
    char str2[] = "abcd";
    char str3[] = "abce";
    printf("strncmp: original=%d, custom=%d\n", strncmp(str2, str3, 3), ft_strncmp(str2, str3, 3));

	// Test ft_strnstr
    const char haystack[] = "Hello, World!";
    const char needle[] = "World";
    char *resultstr = ft_strnstr(haystack, needle, sizeof(haystack));
    if (resultstr != NULL)
        printf("Substring found at position: %ld\n", resultstr - haystack);
    else
        printf("Substring not found\n");

    // Test ft_strcat
    char destcat[20] = "Hello, ";
    const char srccat[] = "World!";

    // Using ft_strlcat
    size_t new_len = ft_strlcat(destcat, srccat, sizeof(destcat));
    printf("Concatenated string: %s\n", destcat);
    printf("New length of the string: %zu\n", new_len);

	//strcpy
	char srccpy[] = "Hello, World!";
    char destcpy[10];

    size_t lencpy = ft_strlcpy(destcpy, srccpy, sizeof(destcpy));
    printf("Destination string after ft_strlcpy: %s\n", destcpy);
    printf("Length of the source string: %zu\n", lencpy);

	//strdup
	const char srcdup[] = "Hello, World!";

    // Using standard strdup
    char *duplicate_std = strdup(srcdup);
    if (duplicate_std != NULL) {
        printf("Original string: %s\n", srcdup);
        printf("Duplicated string using strdup: %s\n", duplicate_std);
        free(duplicate_std); // Remember to free the allocated memory
    } else {
        printf("Failed to duplicate the string using strdup.\n");
    }

    // Using custom ft_strdup
    char *duplicate_ft = ft_strdup(srcdup);
    if (duplicate_ft != NULL) {
        printf("Duplicated string using ft_strdup: %s\n", duplicate_ft);
        free(duplicate_ft); // Remember to free the allocated memory
    } else {
        printf("\nFailed to duplicate the string using ft_strdup.\n");
    }

    // memchr
    char arr3[] = "This is a string";
    printf("memchr: original=%p, custom=%p\n", memchr(arr3, 'a', strlen(arr3)), ft_memchr(arr3, 'a', strlen(arr3)));

    // memcmp
    char arr4[] = "abcd";
    char arr5[] = "abce";
    printf("memcmp: original=%d, custom=%d\n", memcmp(arr4, arr5, 4), ft_memcmp(arr4, arr5, 4));

    // atoi
    char num[] = "12345";
    printf("atoi: original=%d, custom=%d\n", atoi(num), ft_atoi(num));

    // calloc
    int *ptr = (int *)calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        printf("calloc[%d]: original=%d, custom=%d\n", i, ptr[i], ((int *)ft_calloc(5, sizeof(int)))[i]);
    }
    free(ptr);

    return 0;
}