/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:59:50 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/06 14:19:22 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//To use this testing program, you will need a libft.h ready.
//Other than that, just run the "gcc -Wall -Werror -Wextra Tests.c libft.a && ./a.out" command in the right folder and you should be good to go.
//If you do not have a makefile yet, replace "Tests.c libft.a" with "*.c", or anything else you see fit.
//Do not hesitate to mute some parts of the code if you are missing some functions but want to test your already existing ones, as this
//program will not compile if there isn't every function of libft.

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

static void	ft_free(char **split)
{
	int	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	mapi(unsigned int i, char s)
{
	if (i < 8)
		return (ft_toupper(s));
	else
		return (ft_tolower(s));
}

static char	mapi2(unsigned int i, char s)
{
	if (i < 5)
		return (ft_tolower(s));
	else
		return (ft_toupper(s));
}

static void	iteri(unsigned int i, char *s)
{
	if (i < 8)
		*s = ft_tolower(*s);
	else
		*s = ft_toupper(*s);
}

static void	iteri2(unsigned int i, char *s)
{
	if (i < 5)
		*s = ft_toupper(*s);
	else
		*s = ft_tolower(*s);
}

int	main()
{
	int		i = -1;
	char	*s0 = "";
	char	*s1 = "1";
	char	*s2 = "1234567890abc";
	char	*s3 = "   \n\r  \f \v \t ";
	char	*s4 = "Jambonfromagequiroulemal";
	char	b0[100];
	char	b1[100];
	char	*m1;
	char	*m2;
	char	**split1;
	char	**split2;
	//isalpha
	printf ("ft_isalpha :");
	while (i < 130)
	{
		if (ft_isalpha(i) == isalpha(i))
			i++;
		else
		{
			printf (" KO\nft_isalpha(%d) = %d, isalpha(%d) = %d\n", i, ft_isalpha(i), i, isalpha(i));
			return (1);
		}
	}
	//isdigit
	printf (" OK !\nft_isdigit :");
	i = -1;
	while (i < 130)
	{
		if (ft_isdigit(i) == isdigit(i))
			i++;
		else
		{
			printf (" KO\nft_isdigit(%d) = %d, isdigit(%d) = %d\n", i, ft_isdigit(i), i, isdigit(i));
			return (1);
		}
	}
	//isalnum
	printf (" OK !\nft_isalnum :");
	i = -1;
	while (i < 130)
	{
		if (ft_isalnum(i) == isalnum(i))
			i++;
		else
		{
			printf (" KO\nft_isalnum(%d) = %d, isalnum(%d) = %d\n", i, ft_isalnum(i), i, isalnum(i));
			return (1);
		}
	}
	//isascii
	printf (" OK !\nft_isascii :");
	i = -1;
	while (i < 130)
	{
		if (ft_isascii(i) == isascii(i))
			i++;
		else
		{
			printf (" KO\nft_isascii(%d) = %d, isascii(%d) = %d\n", i, ft_isascii(i), i, isascii(i));
			return (1);
		}
	}
	//isprint
	printf (" OK !\nft_isprint :");
	i = -1;
	while (i < 130)
	{
		if (ft_isprint(i) == isprint(i))
			i++;
		else
		{
			printf (" KO\nft_isprint(%d) = %d, isprint(%d) = %d\n", i, ft_isprint(i), i, isprint(i));
			return (1);
		}
	}
	//strlen
	printf (" OK !\nft_strlen :");
	if (ft_strlen(s1) != strlen(s1))
	{
		printf (" KO\nft_strlen(s1) = %lu, strlen(s1) = %lu\n", ft_strlen(s1), strlen(s1));
		return (1);
	}
	if (ft_strlen(s2) != strlen(s2))
	{
		printf (" KO\nft_strlen(s2) = %lu, strlen(s2) = %lu\n", ft_strlen(s2), strlen(s2));
		return (1);
	}
	if (ft_strlen(s3) != strlen(s3))
	{
		printf (" KO\nft_strlen(s3) = %lu, strlen(s3) = %lu\n", ft_strlen(s3), strlen(s3));
		return (1);
	}
	if (ft_strlen(s0) != strlen(s0))
	{
		printf (" KO\nft_strlen(s0) = %lu, strlen(s0) = %lu\n", ft_strlen(s0), strlen(s0));
		return (1);
	}
	//memset
	printf (" OK !\nft_memset :");
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memset(b0, 1337, 13), ft_memset(b1, 1337, 13), 14))
	{
		printf (" KO\nParams : 1337, 13\nmemset = %s\n", b0);
		printf ("ft_memset = %s\n", ft_memset(b1, 1337, 13));
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memset(b0, 42, 1), ft_memset(b1, 42, 1), 2))
	{
		printf (" KO\nParams : 42, 1\nmemset = %s\n", b0);
		printf ("ft_memset = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memset(b0, 5, (0)), ft_memset(b1, 5, (0)), 1))
	{
		printf (" KO\nParams : 5, 0\nmemset = %s\n", b0);
		printf ("ft_memset = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	//bzero
	printf (" OK !\nft_bzero :");
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	bzero(b0, 30);
	ft_bzero(b1, 30);
	if (memcmp(b0, b1, 31))
	{
		printf (" KO\nParams : s4, 30\n");
		return (1);
	}
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	bzero(b0, 13);
	ft_bzero(b1, 13);
	if (memcmp(b0, b1, 17))
	{
		printf (" KO\nParams : s4, 13\n");
		return (1);
	}
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	bzero(b0, 1);
	ft_bzero(b1, 1);
	if (memcmp(b0, b1, 5))
	{
		printf (" KO\nParams : s4, 1\n");
		return (1);
	}
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	bzero(b0, (0));
	ft_bzero(b1, 0);
	if (memcmp(b0, b1, 5))
	{
		printf (" KO\nParams : s4, 0\n");
		return (1);
	}
	//memcpy
	printf (" OK !\nft_memcpy :");
	if (memcmp(memcpy(b0, s0, 13), ft_memcpy(b1, s0, 13), 14))
	{
		printf(" KO\nParams : s0, 13\nmemcpy = %s\n", b0);
		printf("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s1, 0), ft_memcpy(b1, s1, 0), 1))
	{
		printf (" KO\nParams : s1, 0\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s1, 1), ft_memcpy(b1, s1, 1), 2))
	{
		printf (" KO\nParams : s1, 1\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s1, 3), ft_memcpy(b1, s1, 3), 4))
	{
		printf (" KO\nParams : s1, 3\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s2, 1), ft_memcpy(b1, s2, 1), 2))
	{
		printf (" KO\nParams : s2, 1\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s2, 0), ft_memcpy(b1, s2, 0), 1))
	{
		printf (" KO\nParams : s2, 0\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s2, 13), ft_memcpy(b1, s2, 13), 14))
	{
		printf (" KO\nParams : s2, 13\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memcpy(b0, s3, 7), ft_memcpy(b1, s3, 7), 8))
	{
		printf (" KO\nParams : s3, 7\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	// Only use the following if you want to reproduce the overlap behavior of memcpy
	/*strlcpy (b0, s2, 25);
	strlcpy (b1, s2, 25);
	if (memcmp(memcpy(&b0[5], b0, 11), ft_memcpy(&b1[5], b1, 11), 12))
	{
		printf (" KO\nParams : overlap (s4), dest = src + 5\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy (b0, s4, 25);
	strlcpy (b1, s4, 25);
	if (memcmp(memcpy(b0, &b0[5], 11), ft_memcpy(b1, &b1[5], 11), 12))
	{
		printf (" KO\nParams : overlap (s4), src = dest + 5\nmemcpy = %s\n", b0);
		printf ("ft_memcpy = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);*/
	//memmove
	printf (" OK !\nft_memmove :");
	if (memcmp(memmove(b0, s0, 13), ft_memmove(b1, s0, 13), 14))
	{
		printf (" KO\nParams : s0, 13\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s1, 0), ft_memmove(b1, s1, 0), 1))
	{
		printf (" KO\nParams : s1, 0\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s1, 1), ft_memmove(b1, s1, 1), 2))
	{
		printf (" KO\nParams : s1, 1\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s1, 3), ft_memmove(b1, s1, 3), 4))
	{
		printf (" KO\nParams : s1, 3\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s2, 1), ft_memmove(b1, s2, 1), 2))
	{
		printf (" KO\nParams : s2, 1\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s2, 0), ft_memmove(b1, s2, 0), 1))
	{
		printf (" KO\nParams : s2, 0\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s2, 13), ft_memmove(b1, s2, 13), 14))
	{
		printf (" KO\nParams : s2, 13\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (memcmp(memmove(b0, s3, 7), ft_memmove(b1, s3, 7), 8))
	{
		printf (" KO\nParams : s3, 7\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy (b0, s4, 25);
	strlcpy (b1, s4, 25);
	if (memcmp(memmove(&b0[5], b0, 11), ft_memmove(&b1[5], b1, 11), 12))
	{
		printf (" KO\nParams : overlap (s4), dest = src + 5\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy (b0, s4, 25);
	strlcpy (b1, s4, 25);
	if (memcmp(memmove(b0, &b0[5], 11), ft_memmove(b1, &b1[5], 11), 12))
	{
		printf (" KO\nParams : overlap (s4), src = dest + 5\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy (b0, s4, 25);
	strlcpy (b1, s4, 25);
	if (memcmp(memmove(b0, b0, 11), ft_memmove(b1, b1, 11), 12))
	{
		printf (" KO\nParams : s4, src = dest\nmemmove = %s\n", b0);
		printf ("ft_memmove = %s\n", b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	//strlcpy
	printf (" OK !\nft_strlcpy :");
	if (strlcpy(b0, s2, 13) != ft_strlcpy(b1, s2, 13) || strcmp(b0, b1))
	{
		printf (" KO\nParams : 13, s2\nstrlcpy = %lu, %s\nft_strlcpy = %lu, %s\n", strlcpy(b0, s2, 13), b0, ft_strlcpy(b1, s2, 13), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcpy(b0, s2, 29) != ft_strlcpy(b1, s2, 29) || strcmp(b0, b1))
	{
		printf (" KO\nParams : 29, s2\nstrlcpy = %lu, %s\nft_strlcpy = %lu, %s\n", strlcpy(b0, s2, 29), b0, ft_strlcpy(b1, s2, 29), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcpy(b0, s3, 5) != ft_strlcpy(b1, s3, 5) || strcmp(b0, b1))
	{
		printf (" KO\nParams : 5, s3\nstrlcpy = %lu, %s\nft_strlcpy = %lu, %s\n", strlcpy(b0, s3, 5), b0, ft_strlcpy(b1, s3, 5), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcpy(b0, s0, 5) != ft_strlcpy(b1, s0, 5) || strcmp(b0, b1))
	{
		printf (" KO\nParams : 5, s0\nstrlcpy = %lu, %s\nft_strlcpy = %lu, %s\n", strlcpy(b0, s0, 5), b0, ft_strlcpy(b1, s0, 5), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcpy(b0, s1, 0) != ft_strlcpy(b1, s1, 0) || strcmp(b0, b1))
	{
		printf (" KO\nParams : 0, s1\nstrlcpy = %lu, %s\nft_strlcpy = %lu, %s\n", strlcpy(b0, s1, 0), b0, ft_strlcpy(b1, s1, 0), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcpy(b0, s2, 0) != ft_strlcpy(b1, s2, 0) || strcmp(b0, b1))
	{
		printf (" KO\nParams : 0, s2\nstrlcpy = %lu, %s\nft_strlcpy = %lu, %s\n", strlcpy(b0, s2, 0), b0, ft_strlcpy(b1, s2, 0), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	//strlcat
	printf (" OK !\nft_strlcat :");
	strlcpy(b0, s2, 10);
	strlcpy(b1, s2, 10);
	if (strlcat(b0, s2, 33) != ft_strlcat(b1, s2, 33) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		strlcpy(b0, s2, 10);
		strlcpy(b1, s2, 10);
		printf (" KO\nParams : 33, s2->s2\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s2, 33), b0, ft_strlcat(b1, s2, 33), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	if (strlcat(b0, s2, 29) != ft_strlcat(b1, s2, 29) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		strlcpy(b0, s4, 30);
		strlcpy(b1, s4, 30);
		printf (" KO\nParams : 29, s2->s4\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s2, 29), b0, ft_strlcat(b1, s2, 29), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	if (strlcat(b0, s2, 13) != ft_strlcat(b1, s2, 13) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		strlcpy(b0, s4, 30);
		strlcpy(b1, s4, 30);
		printf (" KO\nParams : 13, s2->s4\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s2, 13), b0, ft_strlcat(b1, s2, 13), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	if (strlcat(b0, s0, 13) != ft_strlcat(b1, s0, 13) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		strlcpy(b0, s4, 30);
		strlcpy(b1, s4, 30);
		printf (" KO\nParams : 13, s0->s4\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s0, 13), b0, ft_strlcat(b1, s0, 13), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcat(b0, s4, 13) != ft_strlcat(b1, s4, 13) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		printf (" KO\nParams : 13, s4->s0\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s4, 13), b0, ft_strlcat(b1, s4, 13), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	if (strlcat(b0, s2, 0) != ft_strlcat(b1, s2, 0) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		strlcpy(b0, s4, 30);
		strlcpy(b1, s4, 30);
		printf (" KO\nParams : 0, s2->s4\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s2, 0), b0, ft_strlcat(b1, s2, 0), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	if (strlcat(b0, s0, 0) != ft_strlcat(b1, s0, 0) || strcmp(b0, b1))
	{
		memset(b0, 0, 100);
		memset(b1, 0, 100);
		printf (" KO\nParams : 0, s0->s0\nstrlcat = %lu, %s\nft_strlcat = %lu, %s\n", strlcat(b0, s0, 0), b0, ft_strlcat(b1, s0, 0), b1);
		return (1);
	}
	memset(b0, 0, 100);
	memset(b1, 0, 100);
	//toupper
	printf (" OK !\nft_toupper :");
	i = -1;
	while (i < 130)
	{
		if (ft_toupper(i) == toupper(i))
			i++;
		else
		{
			printf (" KO\nft_toupper(%d) = %d, toupper(%d) = %d\n", i, ft_toupper(i), i, toupper(i));
			return (1);
		}
	}
	//tolower
	printf (" OK !\nft_tolower :");
	i = -1;
	while (i < 130)
	{
		if (ft_tolower(i) == tolower(i))
			i++;
		else
		{
			printf (" KO\nft_tolower(%d) = %d, tolower(%d) = %d\n", i, ft_tolower(i), i, tolower(i));
			return (1);
		}
	}
	//strchr
	printf (" OK !\nft_strchr :");
	if (strcmp(strchr(s4, 'J'), ft_strchr(s4, 'J')))
	{
		printf (" KO\nParams : s4, 'J'\nstrchr = %s\nft_strchr = %s\n", strchr(s4, 'J'), ft_strchr(s4, 'J'));
		return (1);
	}
	if (strcmp(strchr(s4, 'o'), ft_strchr(s4, 'o')))
	{
		printf (" KO\nParams : s4, 'o'\nstrchr = %s\nft_strchr = %s\n", strchr(s4, 'o'), ft_strchr(s4, 'o'));
		return (1);
	}
	if (strcmp(strchr(s3, 0), ft_strchr(s3, 0)))
	{
		printf (" KO\nParams : s3, 0\nstrchr = %s\nft_strchr = %s\n", strchr(s3, 0), ft_strchr(s3, 0));
		return (1);
	}
	if (ft_strchr(s2, 'u'))
	{
		printf (" KO\nParams : s2, 'u'\nstrchr = NULL\nft_strchr = %s\n", ft_strchr(s2, 'u'));
		return (1);
	}
	if (strcmp(strchr(s1, '1'), ft_strchr(s1, '1')))
	{
		printf (" KO\nParams : s1, '1'\nstrchr = %s\nft_strchr = %s\n", strchr(s1, '1'), ft_strchr(s1, '1'));
		return (1);
	}
	if (ft_strchr(s0, '8'))
	{
		printf (" KO\nParams : s0, '8'\nstrchr = NULL\nft_strchr = %s\n", ft_strchr(s0, '8'));
		return (1);
	}
	if (strcmp(strchr(s2, '3' + 256), ft_strchr(s2, '3' + 256)))
	{
		printf("KO\nParams : s2, '3' + 256, 3\nstrchr = %s\nft_strchr = %s\n", strchr(s2, '3' + 256), ft_strchr(s2, '3' + 256));
		return (1);
	}
	//strrchr
	printf (" OK !\nft_strrchr :");
	if (strcmp(strrchr(s4, 'e'), ft_strrchr(s4, 'e')))
	{
		printf (" KO\nParams : s4, 'e'\nstrrchr = %s\nft_strrchr = %s\n", strrchr(s4, 'e'), ft_strrchr(s4, 'e'));
		return (1);
	}
	if (strcmp(strrchr(s4, 'o'), ft_strrchr(s4, 'o')))
	{
		printf (" KO\nParams : s4, 'o'\nstrrchr = %s\nft_strrchr = %s\n", strrchr(s4, 'o'), ft_strrchr(s4, 'o'));
		return (1);
	}
	if (strcmp(strrchr(s3, 0), ft_strrchr(s3, 0)))
	{
		printf (" KO\nParams : s3, 0\nstrrchr = %s\nft_strrchr = %s\n", strrchr(s3, 0), ft_strrchr(s3, 0));
		return (1);
	}
	if (ft_strrchr(s2, 'u'))
	{
		printf (" KO\nParams : s2, 'u'\nstrrchr = NULL\nft_strrchr = %s\n", ft_strrchr(s2, 'u'));
		return (1);
	}
	if (strcmp(strrchr(s1, '1'), ft_strrchr(s1, '1')))
	{
		printf (" KO\nParams : s1, '1'\nstrrchr = %s\nft_strrchr = %s\n", strrchr(s1, '1'), ft_strrchr(s1, '1'));
		return (1);
	}
	if (ft_strrchr(s0, '8'))
	{
		printf (" KO\nParams : s0, '8'\nstrrchr = NULL\nft_strrchr = %s\n", ft_strrchr(s0, '8'));
		return (1);
	}
	if (strcmp(strrchr(s2, '3' + 256), ft_strrchr(s2, '3' + 256)))
	{
		printf("KO\nParams : s2, '3' + 256\nstrrchr = %s\nft_strrchr = %s\n", strrchr(s2, '3' + 256), ft_strrchr(s2, '3' + 256));
		return (1);
	}
	if (ft_strrchr(s4, 'Z'))
	{
		printf("KO\nParams : s4, 'Z'\nstrrchr = NULL\nft_strrchr = %s\n", ft_strrchr(s4, 'Z'));
		return (1);
	}
	if (ft_strrchr(&s4[1], 'J'))
	{
		printf("KO\nParams : &s4[1], 'J'\nstrrchr = NULL\nft_strrchr = %s\n", ft_strrchr(&s4[1], 'J'));
		return (1);
	}
	//strncmp
	printf (" OK !\nft_strncmp :");
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	if (strncmp (b0, b1, 30) != ft_strncmp(b0, b1, 30))
	{
		printf (" KO\nParams : s4, s4, 30\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 30), ft_strncmp(b0, b1, 30));
		return (1);
	}
	if (strncmp (b0, b1, 13) != ft_strncmp(b0, b1, 13))
	{
		printf (" KO\nParams : s4, s4, 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	if (strncmp (b0, b1, 1) != ft_strncmp(b0, b1, 1))
	{
		printf (" KO\nParams : s4, s4, 1\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 1), ft_strncmp(b0, b1, 1));
		return (1);
	}
	if (strncmp (b0, b1, 0) != ft_strncmp(b0, b1, 0))
	{
		printf (" KO\nParams : s4, s4, 0\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 0), ft_strncmp(b0, b1, 0));
		return (1);
	}
	b0[13] = 2;
	if (strncmp (b0, b1, 14) != ft_strncmp(b0, b1, 14) && ft_strncmp(b0, b1, 14) != -1)
	{
		printf (" KO\nParams : s4[13]=2, s4, 14\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 14), ft_strncmp(b0, b1, 14));
		return (1);
	}
	if (strncmp (b0, b1, 13) != ft_strncmp(b0, b1, 13))
	{
		printf (" KO\nParams : s4[13]=2, s4, 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	if (strncmp (b0, b1, 12) != ft_strncmp(b0, b1, 12))
	{
		printf (" KO\nParams : s4[13]=2, s4, 12\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 12), ft_strncmp(b0, b1, 12));
		return (1);
	}
	b1[7] = 3;
	if (strncmp (b0, b1, 8) != ft_strncmp(b0, b1, 8) && ft_strncmp(b0, b1, 8) != 1)
	{
		printf (" KO\nParams : s4, s4[7]=3, 8\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 8), ft_strncmp(b0, b1, 8));
		return (1);
	}
	if (strncmp (b0, b1, 7) != ft_strncmp(b0, b1, 7))
	{
		printf (" KO\nParams : s4, s4[7]=3, 7\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 7), ft_strncmp(b0, b1, 7));
		return (1);
	}
	if (strncmp (b0, b1, 6) != ft_strncmp(b0, b1, 6))
	{
		printf (" KO\nParams : s4, s4[7]=3, 6\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 6), ft_strncmp(b0, b1, 6));
		return (1);
	}
	bzero (b0, 30);
	bzero (b1, 30);
	if (strncmp (b0, b1, 13) != ft_strncmp(b0, b1, 13))
	{
		printf (" KO\nParams : s0, s0, 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	b1[0] = '\200';
	if (strncmp (b0, b1, 13) != ft_strncmp(b0, b1, 13) && ft_strncmp(b0, b1, 13) != -1)
	{
		printf (" KO\nParams : s0, s0[0] = '\\200', 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	b0[0] = '\200';
	bzero (b1, 2);
	if (strncmp (b0, b1, 13) != ft_strncmp(b0, b1, 13) && ft_strncmp(b0, b1, 13) != 1)
	{
		printf (" KO\nParams : s0[0] = '\\200', s0, 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	bzero (b0, 2);
	strcpy(b0, "\x12\xfe\x65\x12\xbd\xde\xad");
	strcpy(b1, "\x12\x04");
	if (strncmp (b0, b1, 13) != ft_strncmp(b0, b1, 13) && ft_strncmp(b0, b1, 13) != 1)
	{
		printf (" KO\nParams : \"\\x12\\xfe\\x65\\x12\\xbd\\xde\\xad\", \"\\x12\\x04\", 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	bzero (b0, 10);
	bzero (b1, 10);
	strcpy(b0, "\x12\xfe\x65\x12\xbd\xde\xad");
	strcpy(b1, "\x12\xfe\x65\x12\xfd");
	if (strncmp (b0, b1, 13) == ft_strncmp(b0, b1, 13) && ft_strncmp(b0, b1, 13) != -1)
	{
		printf (" KO\nParams : \"\\x12\\xfe\\x65\\x12\\xbd\\xde\\xad\", \"\\x12\\xfe\\x65\\x12\\xfd\", 13\nstrncmp = %i, ft_strncmp = %i\n", strncmp(b0, b1, 13), ft_strncmp(b0, b1, 13));
		return (1);
	}
	bzero (b0, 10);
	bzero (b1, 10);
	//memchr
	printf (" OK !\nft_memchr :");
	if (memcmp(memchr(s4, 'J', 30), ft_memchr(s4, 'J', 30), 30))
	{
		printf (" KO\nParams : s4, 'J', 30\nmemchr = %s\nft_memchr = %s\n", memchr(s4, 'J', 30), ft_memchr(s4, 'J', 30));
		return (1);
	}
	if (memcmp(memchr(s4, 'o', 30), ft_memchr(s4, 'o', 30), 30))
	{
		printf (" KO\nParams : s4, 'o', 30\nmemchr = %s\nft_memchr = %s\n", memchr(s4, 'o', 30), ft_memchr(s4, 'o', 30));
		return (1);
	}
	if (memcmp(memchr(s3, 0, 30), ft_memchr(s3, 0, 30), 30))
	{
		printf (" KO\nParams : s3, 0, 30\nmemchr = %s\nft_memchr = %s\n", memchr(s3, 0, 30), ft_memchr(s3, 0, 30));
		return (1);
	}
	if (ft_memchr(s2, 'u', 13))
	{
		printf (" KO\nParams : s2, 'u', 13\nmemchr = NULL\nft_memchr = %s\n", ft_memchr(s2, 'u', 13));
		return (1);
	}
	if (memcmp(memchr(s1, '1', 2), ft_memchr(s1, '1', 2), 2))
	{
		printf (" KO\nParams : s1, '1', 2\nmemchr = %s\nft_memchr = %s\n", memchr(s1, '1', 2), ft_memchr(s1, '1', 2));
		return (1);
	}
	if (ft_memchr(s0, '8', 1))
	{
		printf (" KO\nParams : s0, '8', 1\nmemchr = NULL\nft_memchr = %s\n", ft_memchr(s0, '8', 1));
		return (1);
	}
	if (ft_memchr(s2, '3', 2))
	{
		printf (" KO\nParams : s2, '3', 2\nmemchr = NULL\nft_memchr = %s\n", ft_memchr(s2, '3', 2));
		return (1);
	}
	if (memcmp(memchr(s2, '3', 3), ft_memchr(s2, '3', 3), 3))
	{
		printf (" KO\nParams : s2, '3', 3\nmemchr = %s\nft_memchr = %s\n", memchr(s2, '3', 3), ft_memchr(s2, '3', 3));
		return (1);
	}
	if (memcmp(memchr(s2, '3' + 256, 3), ft_memchr(s2, '3' + 256, 3), 3))
	{
		printf("KO\nParams : s2, '3' + 256, 3\nmemchr = %s\nft_memchr = %s\n", memchr(s2, '3' + 256, 3), ft_memchr(s2, '3' + 256, 3));
		return (1);
	}
	//memcmp
	printf (" OK !\nft_memcmp :");
	strlcpy(b0, s4, 30);
	strlcpy(b1, s4, 30);
	if (memcmp (b0, b1, 30) != ft_memcmp(b0, b1, 30))
	{
		printf (" KO\nParams : s4, s4, 30\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 30), ft_memcmp(b0, b1, 30));
		return (1);
	}
	if (memcmp(b0, b1, 13) != ft_memcmp(b0, b1, 13))
	{
		printf (" KO\nParams : s4, s4, 13\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 13), ft_memcmp(b0, b1, 13));
		return (1);
	}
	if (memcmp(b0, b1, 1) != ft_memcmp(b0, b1, 1))
	{
		printf (" KO\nParams : s4, s4, 1\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 1), ft_memcmp(b0, b1, 1));
		return (1);
	}
	if (memcmp(b0, b1, 0) != ft_memcmp(b0, b1, 0))
	{
		printf (" KO\nParams : s4, s4, 0\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 0), ft_memcmp(b0, b1, 0));
		return (1);
	}
	b0[13] = 2;
	if (memcmp(b0, b1, 14) != ft_memcmp(b0, b1, 14))
	{
		printf (" KO\nParams : s4[13]=2, s4, 14\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 14), ft_memcmp(b0, b1, 14));
		return (1);
	}
	if (memcmp(b0, b1, 13) != ft_memcmp(b0, b1, 13))
	{
		printf (" KO\nParams : s4[13]=2, s4, 13\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 13), ft_memcmp(b0, b1, 13));
		return (1);
	}
	if (memcmp(b0, b1, 12) != ft_memcmp(b0, b1, 12))
	{
		printf (" KO\nParams : s4[13]=2, s4, 12\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 12), ft_memcmp(b0, b1, 12));
		return (1);
	}
	b1[7] = 3;
	if (memcmp(b0, b1, 8) != ft_memcmp(b0, b1, 8))
	{
		printf (" KO\nParams : s4, s4[7]=3, 8\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 8), ft_memcmp(b0, b1, 8));
		return (1);
	}
	if (memcmp(b0, b1, 7) != ft_memcmp(b0, b1, 7))
	{
		printf (" KO\nParams : s4, s4[7]=3, 7\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 7), ft_memcmp(b0, b1, 7));
		return (1);
	}
	if (memcmp(b0, b1, 6) != ft_memcmp(b0, b1, 6))
	{
		printf (" KO\nParams : s4, s4[7]=3, 6\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 6), ft_memcmp(b0, b1, 6));
		return (1);
	}
	bzero(b0, 30);
	bzero(b1, 30);
	if (memcmp(b0, b1, 13) != ft_memcmp(b0, b1, 13))
	{
		printf (" KO\nParams : s0, s0, 13\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 13), ft_memcmp(b0, b1, 13));
		return (1);
	}
	b1[0] = '\200';
	if (memcmp(b0, b1, 13) != ft_memcmp(b0, b1, 13))
	{
		printf (" KO\nParams : s0, s0[0] = '\\200', 13\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 13), ft_memcmp(b0, b1, 13));
		return (1);
	}
	b0[0] = '\200';
	bzero(b1, 2);
	if (memcmp(b0, b1, 13) != ft_memcmp(b0, b1, 13))
	{
		printf (" KO\nParams : s0[0] = '\\200', s0, 13\nmemcmp = %i, ft_memcmp = %i\n", memcmp(b0, b1, 13), ft_memcmp(b0, b1, 13));
		return (1);
	}
	bzero(b0, 2);
	//strnstr
	printf (" OK !\nft_strnstr :");
	if (strcmp(strnstr(s4, "mal", 30), ft_strnstr(s4, "mal", 30)))
	{
		printf (" KO\nParams : \"mal\" -> s4, 30\nstrnstr = %s\nft_strnstr = %s\n", strnstr(s4, "mal", 30), ft_strnstr(s4, "mal", 30));
		return (1);
	}
	if (strcmp(strnstr(s4, "ma", 11), ft_strnstr(s4, "ma", 11)))
	{
		printf (" KO\nParams : \"ma\" -> s4, 11\nstrnstr = %s\nft_strnstr = %s\n", strnstr(s4, "ma", 11), ft_strnstr(s4, "ma", 11));
		return (1);
	}
	if (ft_strnstr(s4, "ma", 10))
	{
		printf (" KO\nParams : \"ma\" -> s4, 10\nstrnstr = NULL\nft_strnstr = %s\n", ft_strnstr(s4, "ma", 10));
		return (1);
	}
	if (ft_strnstr(s4, "ma", 0))
	{
		printf (" KO\nParams : \"ma\" -> s4, 0\nstrnstr = %s\nft_strnstr = %s\n", strnstr(s4, "ma", 0), ft_strnstr(s4, "ma", 0));
		return (1);
	}
	if (strcmp(strnstr(s4, "", 4), ft_strnstr(s4, "", 4)))
	{
		printf (" KO\nParams : \"\" -> s4, 4\nstrnstr = %s\nft_strnstr = %s\n", strnstr(s4, "", 4), ft_strnstr(s4, "", 4));
		return (1);
	}
	if (strcmp(strnstr(s0, "", 4), ft_strnstr(s0, "", 4)))
	{
		printf (" KO\nParams : \"\" -> s0, 4\nstrnstr = %s\nft_strnstr = %s\n", strnstr(s0, "", 4), ft_strnstr(s0, "", 4));
		return (1);
	}
	//atoi
	printf (" OK !\nft_atoi :");
	strlcpy(b0, "       -50a", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " \t\n\r\v\f+0952", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \" \\t\\n\\r\\v\\f+0952\"\natoi = %i, ft_atoi = %i\n", atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, "   85 42", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, "   +85-42", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, "   --85 42", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, "   +-85 42", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, "   -+85 42", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -1", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -0", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " +1", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " a  9223372036854775807", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 19489384723948723948", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -19489384723948723948", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 9223372036854775809", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -9223372036854775809", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 9223372036854775808", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -9223372036854775808", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 9223372036854775807", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -9223372036854775807", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 9223372036854775806", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -9223372036854775806", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 1313131313131313", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -1313131313131313", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -2147483649", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " 2147483648", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	strlcpy(b0, " -2147483648", 30);
	if (atoi(b0) != ft_atoi(b0))
	{
		printf (" KO\nTest : \"%s\"\natoi = %i, ft_atoi = %i\n", b0, atoi(b0), ft_atoi(b0));
		return (1);
	}
	bzero(b0, 30);
	//calloc
	printf (" OK !\nft_calloc :");
	m1 = calloc(5, sizeof (char));
	m2 = ft_calloc(5, sizeof (char));
	if (memcmp(m1, m2, 6 * sizeof (char)))
	{
		printf (" KO\nParams : 5, sizeof (char)");
		return (1);
	}
	free(m1);
	free(m2);
	m1 = calloc(2, sizeof (char *));
	m2 = ft_calloc(2, sizeof (char *));
	if (memcmp(m1, m2, 2 * sizeof (char *)))
	{
		printf (" KO\nParams : 2, sizeof (char *)");
		return (1);
	}
	free(m1);
	free(m2);
	m1 = calloc(0, sizeof (int));
	m2 = ft_calloc(0, sizeof (int));
	if (memcmp(m1, m2, sizeof (int)))
	{
		printf (" KO\nParams : 0, sizeof (int)");
		return (1);
	}
	free(m1);
	free(m2);
	m1 = calloc(13, 0);
	m2 = ft_calloc(13, 0);
	if (memcmp(m1, m2, 1))
	{
		printf (" KO\nParams : 13, 0");
		return (1);
	}
	free(m1);
	free(m2);
	//Here is the search about the mysteries of calloc's maximum allocation capacity. I did not find out what it is. Some say it is the number
	//entered in ft_calloc, but calloc still works with it. It even works with ten billion.
	//Maybe calloc only allocates up to 2GB and allocates 2GB if it's asked to do more than that ? In that case, why did I not find it out with
	//memcmp, maybe size_t reached its limit ? Or maybe I transformed all the free memory on this pc into '/0' ?
	//I have no idea. Conclusion, you can fiddle around a bit if you want, I wasn't able to find out what is happening (and am not testing it).
	//Edit : https://vorpus.org/blog/why-does-calloc-exist/
	/*m1 = calloc(10000000000, 1);
	m2 = ft_calloc(2147483424, 1);
	if (memcmp(m1, m2, 2200000000))
	{
		printf (" KO\nParams : 13, 0");
		return (1);
	}
	free(m1);
	free(m2);*/
	//strdup
	printf (" OK ?*\nft_strdup :");
	m1 = strdup(s4);
	m2 = ft_strdup(s4);
	if (strcmp(m1, m2))
	{
		printf (" KO\nstrdup : \"%s\"\nft_strdup : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s3);
	m2 = ft_strdup(s3);
	if (strcmp(m1, m2))
	{
		printf (" KO\nstrdup : \"%s\"\nft_strdup : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s2);
	m2 = ft_strdup(s2);
	if (strcmp(m1, m2))
	{
		printf (" KO\nstrdup : \"%s\"\nft_strdup : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s1);
	m2 = ft_strdup(s1);
	if (strcmp(m1, m2))
	{
		printf (" KO\nstrdup : \"%s\"\nft_strdup : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_strdup(s0);
	if (strcmp(m1, m2))
	{
		printf (" KO\nstrdup : \"%s\"\nft_strdup : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	//substr
	//I decided not to test anything that is not specified by the subject (e.g. start > strlen(string))
	printf (" OK ?*\nFrom here on, every function is tested however I understand they should behave.\nft_substr :");
	m1 = strdup("Jambonfromageq");
	m2 = ft_substr(s4, 0, 14);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4, 0, 14\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("fromagequiroulem");
	m2 = ft_substr(s4, 6, 16);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4, 6, 16\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("fromagequiroulemal");
	m2 = ft_substr(s4, 6, 100);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4, 6, 21\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_substr(s0, 0, 2);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s0, 0, 2\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_substr(s1, 1, 2);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s1, 1, 2\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_substr(s4, 6, 0);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4, 6, 0\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("a");
	m2 = ft_substr(s4, 1, 1);
	if (memcmp(m1, m2, 2))
	{
		printf (" KO\nParams : s4, 100, 1\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	printf (" OK ?*\nft_strjoin :");
	m1 = strdup("Jambonfromagequiroulemal");
	m2 = ft_strjoin(s4, s0);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4 + s0\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("Jambonfromagequiroulemal");
	m2 = ft_strjoin(s0, s4);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s0 + s4\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("Jambonfromagequiroulemal1234567890abc");
	m2 = ft_strjoin(s4, s2);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4 + s2\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("11");
	m2 = ft_strjoin(s1, s1);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s1 + s1\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_strjoin(s0, s0);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s0 + s0\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	//strtrim
	printf (" OK ?*\nft_strtrim :");
	m1 = strdup(s4);
	m2 = ft_strtrim(s4, s0);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s0 trimming s4\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("ambonfromagequiroulema");
	m2 = ft_strtrim(s4, "Jl");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : \"Jl\" trimming s4\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("gequiroulemal");
	m2 = ft_strtrim(s4, "Jambonfroma");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : \"Jambonfroma\" trimming s4\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("bonfromagequi");
	m2 = ft_strtrim(s4, "roulemalJ");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s0 trimming s4\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_strtrim(s4, "Jambonfrgequil");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : \"Jambonfrgequil\" trimming s4\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s2);
	m2 = ft_strtrim(s2, "234567890ab");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : \"234567890ab\" trimming s3\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_strtrim(s0, s4);
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : s4 trimming s0\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_strtrim("        ", " ");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : \" \" trimming \"        \"\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup(s0);
	m2 = ft_strtrim(s3, " \t\n\r\v\f");
	if (strcmp(m1, m2))
	{
		printf (" KO\nParams : \" \\t\\n\\r\\v\\f\" trimming s3\nexpected : \"%s\"\nft_strtrim : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	//split
	printf (" OK ?*\nft_split :");
	//test 1
	split1 = malloc(2 * sizeof (char *));
	if (!split1)
	{
		printf(" ??\nA malloc failed during testing.\n");
		return (1);
	}
	split1[0] = strdup(s4);
	if (!split1[0])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[1] = NULL;
	split2 = ft_split(s4, ' ');
	if (!split2)
	{
		printf(" ??\nA malloc failed during testing (or ft_split does not return anything).\n");
		ft_free(split1);
		return (1);
	}
	if (strcmp(split1[0], split2[0]) || split2[1] != NULL)
	{
		printf (" KO\nParams : s4 splitted by ' '\nexpected : \n\"%s\"\n\nft_slip : \n\"%s\"\n", split1[0], split2[0]);
		return (1);
	}
	ft_free(split1);
	ft_free(split2);
	//test 2
	split1 = malloc(5 * sizeof (char *));
	if (!split1)
	{
		printf(" ??\nA malloc failed during testing.\n");
		return (1);
	}
	split1[0] = strdup("Ja");
	if (!split1[0])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[1] = strdup("bonfro");
	if (!split1[1])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[2] = strdup("agequiroule");
	if (!split1[2])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[3] = strdup("al");
	if (!split1[3])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[4] = NULL;
	split2 = ft_split(s4, 'm');
	if (!split2)
	{
		printf(" ??\nA malloc failed during testing (or ft_split does not return anything).\n");
		ft_free(split1);
		return (1);
	}
	if (strcmp(split1[0], split2[0]) || strcmp(split1[1], split2[1]) || strcmp(split1[2], split2[2]) || strcmp(split1[3], split2[3]) || split2[4] != NULL)
	{
		printf (" KO\nParams : s4 splitted by 'm'\nexpected : \n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\nft_slip : \n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n", split1[0], split1[1], split1[2], split1[3], split2[0], split2[1], split2[2], split2[3]);
		return (1);
	}
	ft_free(split1);
	ft_free(split2);
	//test 3
	split2 = ft_split(s0, ' ');
	if (!split2)
	{
		printf(" ??\nA malloc failed during testing (or ft_split does not return anything).\n");
		ft_free(split1);
		return (1);
	}
	if (split2[0] != NULL)
	{
		printf (" KO\nParams : s0 splitted by ' '\nexpected : \n\"%s\"\n\nft_strtrim : \n\"%s\"\n", split1[0], split2[0]);
		return (1);
	}
	ft_free(split2);
	printf("\noui\n");
	//test 4
	split1 = malloc(2 * sizeof (char *));
	if (!split1)
	{
		printf(" ??\nA malloc failed during testing.\n");
		return (1);
	}
	split1[0] = strdup(s4);
	if (!split1[0])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[1] = NULL;
	split2 = ft_split(s4, 0);
	if (!split2)
	{
		printf(" ??\nA malloc failed during testing (or ft_split does not return anything).\n");
		ft_free(split1);
		return (1);
	}
	if (strcmp(split1[0], split2[0]) || split2[1] != NULL)
	{
		printf (" KO\nParams : s4 splitted by '\\0'\nexpected : \n\"%s\"\n\nft_slip : \n\"%s\"\n", split1[0], split2[0]);
		return (1);
	}
	ft_free(split1);
	ft_free(split2);
	//test 5
	split1 = malloc(2 * sizeof (char *));
	if (!split1)
	{
		printf(" ??\nA malloc failed during testing.\n");
		return (1);
	}
	split1[0] = strdup("a");
	if (!split1[0])
	{
		printf(" ??\nA malloc failed during testing.\n");
		ft_free(split1);
		return (1);
	}
	split1[1] = NULL;
	split2 = ft_split("jjajj", 'j');
	if (!split2)
	{
		printf(" ??\nA malloc failed during testing (or ft_split does not return anything).\n");
		ft_free(split1);
		return (1);
	}
	if (strcmp(split1[0], split2[0]) || split2[1] != NULL)
	{
		printf (" KO\nParams : \"jjajj\" splitted by 'j'\nexpected : \n\"%s\"\n\nft_slip : \n\"%s\"\n", split1[0], split2[0]);
		return (1);
	}
	ft_free(split1);
	ft_free(split2);
	//itoa
	printf (" OK ?*\nft_itoa :");
	m1 = strdup("100111");
	m2 = ft_itoa(100111);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("0");
	m2 = ft_itoa(0);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("-100111");
	m2 = ft_itoa(-100111);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("-2147483648");
	m2 = ft_itoa(-2147483648);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("2147483647");
	m2 = ft_itoa(2147483647);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("-1");
	m2 = ft_itoa(-1);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("1");
	m2 = ft_itoa(1);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_substr : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	//strmapi
	printf(" OK ?*\nft_strmapi :");
	m1 = strdup("JAMBONFRomagequiroulemal");
	m2 = ft_strmapi(s4, mapi);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_strmapi : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	printf(" OK ?*\nft_strmapi :");
	m1 = strdup("jamboNFROMAGEQUIROULEMAL");
	m2 = ft_strmapi(s4, mapi2);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_strmapi : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	//striteri
	printf(" OK ?*\nft_striteri :");
	m1 = strdup("jambonfrOMAGEQUIROULEMAL");
	m2 = strdup(s4);
	ft_striteri(m2, iteri);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_striteri : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	m1 = strdup("JAMBOnfromagequiroulemal");
	m2 = strdup(s4);
	ft_striteri(m2, iteri2);
	if (strcmp(m1, m2))
	{
		printf (" KO\nexpected : \"%s\"\nft_striteri : \"%s\"", m1, m2);
		return (1);
	}
	free(m1);
	free(m2);
	printf(" OK !\n");
	//some tests on the functions using write
	printf("ft_putchar_1 (0 ~): \n");
	ft_putchar_fd('0', 1);
	ft_putchar_fd(' ', 1);
	ft_putchar_fd('~', 1);
	printf("\nft_putstr_1 (s4s2s1s0) :\n");
	ft_putstr_fd(s4, 1);
	ft_putstr_fd(s2, 1);
	ft_putstr_fd(s1, 1);
	ft_putstr_fd(s0, 1);
	printf("\nft_putendl_1 (s4s2s1s0) :\n");
	ft_putendl_fd(s4, 1);
	ft_putendl_fd(s2, 1);
	ft_putendl_fd(s1, 1);
	ft_putendl_fd(s0, 1);
	printf("ft_putnbr_fd :\n");
	printf("2147483647 :\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n110001 :\n");
	ft_putnbr_fd(110001, 1);
	printf("\n1 :\n");
	ft_putnbr_fd(1, 1);
	printf("\n0 :\n");
	ft_putnbr_fd(0, 1);
	printf("\n-6 :\n");
	ft_putnbr_fd(-6, 1);
	printf("\n-110001 :\n");
	ft_putnbr_fd(-110001, 1);
	printf("\n-2147483648 :\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	printf("*Idk how to spot a malloc that is bigger than it is supposed to be (still testing everything else I think of).\nAlso, I don't know how to use file descriptors (for write functions), so I just used standard output 1.");
	return (0);
}
