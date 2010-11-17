#include <stdio.h>
#include <math.h>
#include <malloc.h>

int * aloca_vet(int *v, int tam)
{
	int *p = NULL;
	if(tam == 1)
	{
		p = (int*) malloc(tam * sizeof(int));
		return p;
	}
	else
	{
		p = (int*) realloc(v, tam * sizeof(int));
		return p;
	}
}
void desaloca_vet(int *v)
{
	free(v);
}

static int * copia(int *v, int a, int b, int *u)
{
	int i;

	i = 0;
	while(i<=(b-a))
	{
		v[a+i] = u[i];
		i++;
	}
	return v;
}

static int * intercala(int *v, int a, int m, int b)
{
	int u[b-a];
	int k, i, j, p;

	if(a>=b)
		return v;
	k = 0;
	i = a;
	j = m+1;
	while(k<=b-a)
	{
		if((j>b) || ((i<=m) && (v[i]<=v[j])))
		{
			p = i;
			i++;
		}
		else
		{
			p = j;
			j++;
		}
		u[k] = v[p];
		k++;
	}
	return copia(v,a,b,u);
}

int * ordena_merge(int *v, int a, int b)
{
	double m;

	if(a>=b)
		return v;

	m = (a+b)/2;
	m = fabs(m);

	v = ordena_merge(v,a,(int)m);
	v = ordena_merge(v,(int)m+1,b);
	return intercala(v,a,(int)m,b);
}

static int minimo(int *v, int a, int b)
{
	int i, m;

	i = a;
	m = a;
	while(i<b)
	{
		++i;
		if(v[i]<v[m])
			m = i;
	}
	return m;
}

static void troca(int *v, int a, int b)
{
	int x = v[a];
	v[a] = v[b];
	v[b] = x;
}

int * ordena_sel(int *v, int a, int b)
{
	if(a>=b)
		return v;
	troca(v,a,minimo(v,a,b));
	return ordena_sel(v,a+1,b);
}

