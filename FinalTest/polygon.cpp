#pragma once
#include"polygon.h"
#include"caculate_output.h"
#include<iostream>
polygon::polygon()
{
	size = 3;
	pointCase = pointFst = NULL;
	pointMalloc = 0;
}

polygon::polygon(int _size) {
	size = _size;
	pointCase = pointFst = NULL;
	pointMalloc = 0;
}

void polygon::AddPoint(point a) {
	if (pointMalloc == size) {
		puts("error! no enough malloc!");
		return;
	}
	if (pointCase == NULL) {
		edge* temp = new edge;
		temp->p = a;
		temp->head = temp;
		temp->next = temp;
		pointCase = temp;
		pointFst = temp;
	}
	else {
		edge* temp = new edge;
		temp->p = a;
		temp->head = pointCase;
		temp->next = pointFst;
		pointCase->next = temp;
		pointCase = temp;
		pointFst->head = pointCase;
	}
	pointMalloc++;
}

void polygon::DeletePoint(point a) {
	if (pointMalloc <= 3) {
		puts("error! a polygon must has more than three points");
		return;
	}
	edge* flag = pointFst;
	for (register int i = 0; i < pointMalloc; i++) {
		if (a == flag->p) {
			if (flag == pointFst) {
				pointFst = pointFst->next;
			}
			else if(flag==pointCase){
				pointCase = pointCase->head;
			}
			flag->p.Output();
			flag = flag->next;
			flag->p.Output();
			edge* temp = flag->head;
			flag->head = flag->head->head;
			flag->head->next = flag;
			delete temp;
			pointMalloc--;
			return;
		}
		flag = flag->next;
	}
	puts("error! no such a point in this polygon");
}

void polygon::ChangePoint(point a, point b) {
	edge* flag = pointFst;
	for (register int i = 0; i < pointMalloc; i++) {
		if (a == flag->p) {
			flag->p = b;
			return;
		}
	}
	puts("error! no such a point in this polygon");
}

void polygon::OutputPoint() {
	edge* flag = pointFst;
	for (register int i = 0; i < pointMalloc; i++) {
		(flag->p).SimpleOutput();
		flag = flag->next;
	}
}

int polygon::GetSize() {
	return size;
}

bool polygon::OnPolygon(point a, polygon b) {
	edge* flag = b.pointFst;
	for (register int i = 0; i < b.pointMalloc; i++) {
		vec veca = flag->p - a;
		vec vecb = flag->next->p - flag->p;
		if (Caculate::Cross(veca.x, veca.y, vecb.x, vecb.y) == 0)return true;
		flag = flag->next;
	}
	return false;
}

int polygon::PointPosition(point a, polygon b)
{
	point c = point(a.x + 0.1, a.y + 0.1);
	c.x *= 114514, c.y *= 114514;
	if (polygon::OnPolygon(a, b))return 1;

	return 2;
}

double polygon::GetS() {
	double sum = 0;
	edge* flag=pointFst;
	for (register int i = 0; i < pointMalloc; i++) {
		sum += Caculate::Cross(flag->p.x, flag->p.y, flag->next->p.x, flag->next->p.y) / 2;
		flag = flag->next;
	}
	return abs(sum);
}

double polygon::GetC() {
	double sum = 0;
	edge* flag = pointFst;
	for (register int i = 0; i < pointMalloc; i++) {
		sum += point::GetPointDistance(flag->p, flag->next->p);
		flag = flag->next;
	}
	return abs(sum);
}