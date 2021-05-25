/*
 ******************************************************************
 * backprop.h
 ******************************************************************
 */

#ifndef _BACKPROP_H_

#define _BACKPROP_H_

#define BIGRND 0x7fffffff

/*** ����������ݽṹ�����类�ٶ�Ϊһ��ȫ���ӵ�3��ǰ��ṹ��
	 ÿ��ĵ�Ԫ0����ֵ������ζ����������Ԫ���Ϊ1��n
 ***/

typedef struct {
	int input_n;                  /* ��������Ԫ���� */
	int hidden_n;                 /* ���������Ԫ���� */
	int output_n;                 /* ��������Ԫ���� */

	double *input_units;          /* ��������Ԫ */
	double *hidden_units;         /* ���ز����Ԫ */
	double *output_units;         /* ���������Ԫ */

	double *hidden_delta;         /* ���ز����� */
	double *output_delta;         /* ��������� */

	double *target;               /* Ŀ������ */

	double **input_weights;       /* ����㵽���ز������Ȩ */
	double **hidden_weights;      /* ���ز㵽�����������Ȩ */

                                /*** ���������ڵ���ʱʹ�� ***/
	double **input_prev_weights;  /* ǰ������㵼���ز�Ȩֵ�ĸı� */
	double **hidden_prev_weights; /* ǰ�����ز㵼�����Ȩֵ�ĸı� */
} BPNN;


/*** �û��ӿ� ***/

/* ��ʼ����������� */
void bpnn_initialize(int seed);

/* ����BP���� */
BPNN *bpnn_create(int n_in, int n_hidden, int n_out);

/* �ͷ�BP������ռ���ڴ�ռ� */
void bpnn_free(BPNN *net);

/* ѵ��BP���� */
void bpnn_train(BPNN *net, double eta, double momentum, double *eo, double *eh);

/* ǰ������ */
void bpnn_feedforward(BPNN* net);

/* ����BP���絽�ļ��� */
void bpnn_save(BPNN *net, char *filename);

/* ���ļ��ж�ȡBP������� */
BPNN *bpnn_read(char *filename);


#endif
