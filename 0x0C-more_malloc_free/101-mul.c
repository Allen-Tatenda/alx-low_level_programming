#include "main.h"
2
3/**
4 * _print - moves a string one place to the left and prints the string
5 * @str: string to move
6 * @l: size of string
7 *
8 * Return: void
9 */
10void _print(char *str, int l)
11{
12	int i, j;
13
14	i = j = 0;
15	while (i < l)
16	{
17		if (str[i] != '0')
18			j = 1;
19		if (j || i == l - 1)
20			_putchar(str[i]);
21		i++;
22	}
23
24	_putchar('\n');
25	free(str);
26}
27
28/**
29 * mul - multiplies a char with a string and places the answer into dest
30 * @n: char to multiply
31 * @num: string to multiply
32 * @num_index: last non NULL index of num
33 * @dest: destination of multiplication
34 * @dest_index: highest index to start addition
35 *
36 * Return: pointer to dest, or NULL on failure
37 */
38char *mul(char n, char *num, int num_index, char *dest, int dest_index)
39{
40	int j, k, mul, mulrem, add, addrem;
41
42	mulrem = addrem = 0;
43	for (j = num_index, k = dest_index; j >= 0; j--, k--)
44	{
45		mul = (n - '0') * (num[j] - '0') + mulrem;
46		mulrem = mul / 10;
47		add = (dest[k] - '0') + (mul % 10) + addrem;
48		addrem = add / 10;
49		dest[k] = add % 10 + '0';
50	}
51	for (addrem += mulrem; k >= 0 && addrem; k--)
52	{
53		add = (dest[k] - '0') + addrem;
54		addrem = add / 10;
55		dest[k] = add % 10 + '0';
56	}
57	if (addrem)
58	{
59		return (NULL);
60	}
61	return (dest);
62}
63
64/**
65 * check_for_digits - checks the arguments to ensure they are digits
66 * @av: pointer to arguments
67 *
68 * Return: 0 if digits, 1 if not
69 */
70int check_for_digits(char **av)
71{
72	int i, j;
73
74	for (i = 1; i < 3; i++)
75	{
76		for (j = 0; av[i][j]; j++)
77		{
78			if (av[i][j] < '0' || av[i][j] > '9')
79				return (1);
80		}
81	}
82	return (0);
83}
84
85/**
86 * init - initializes a string
87 * @str: sting to initialize
88 * @l: length of strinf
89 *
90 * Return: void
91 */
92void init(char *str, int l)
93{
94	int i;
95
96	for (i = 0; i < l; i++)
97		str[i] = '0';
98	str[i] = '\0';
99}
100
101/**
102 * main - multiply two numbers
103 * @argc: number of arguments
104 * @argv: argument vector
105 *
106 * Return: zero, or exit status of 98 if failure
107 */
108
109int main(int argc, char *argv[])
110{
111	int l1, l2, ln, ti, i;
112	char *a;
113	char *t;
114	char e[] = "Error\n";
115
116	if (argc != 3 || check_for_digits(argv))
117	{
118		for (ti = 0; e[ti]; ti++)
119			_putchar(e[ti]);
120		exit(98);
121	}
122	for (l1 = 0; argv[1][l1]; l1++)
123		;
124	for (l2 = 0; argv[2][l2]; l2++)
125		;
126	ln = l1 + l2 + 1;
127	a = malloc(ln * sizeof(char));
128	if (a == NULL)
129	{
130		for (ti = 0; e[ti]; ti++)
131			_putchar(e[ti]);
132		exit(98);
133	}
134	init(a, ln - 1);
135	for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
136	{
137		t = mul(argv[2][ti], argv[1], l1 - 1, a, (ln - 2) - i);
138		if (t == NULL)
139		{
140			for (ti = 0; e[ti]; ti++)
141				_putchar(e[ti]);
142			free(a);
143			exit(98);
144		}
145	}
146	_print(a, ln - 1);
147	return (0);
148}
149
