#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
#include"polygon.h"
#include"line-segment.h"
#include"line-ray.h"
using namespace std;
int cutPlace;
void ChangeFinger(int x,int y) {
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}
void ClearOne() {
	int now = 100;
	for (int i = 0; i < now; i++)cout << " ";
	for (int i = 0; i < now; i++)cout << "\b";
}
double read(string cmd) {
	double f = 1;
	double _ = 0;
	int p = cutPlace;
	char c = cmd[p];
	if (p >= cmd.size())return 0;
	while (c > '9' || c < '0') {
		f = (c == '-') ? -1 : 1, p++, c = cmd[p];
		cutPlace = p;
		if (p >= cmd.size())return _*f;
	}
	while (c <= '9' && c >= '0') {
		_ = _ * 10 + (c ^ 48), p++, c = cmd[p];
		cutPlace = p;
		if (p >= cmd.size())return _ * f;
	}
	while (c == '.') {
		p++;
		if (p >= cmd.size())return _ * f;
		c = cmd[p];
		double flag = 0.1;
		while (c <= '9' && c >= '0') {
			_ = _ + flag * (c ^ 48), flag *= 0.1, p++, c = cmd[p];
			if (p >= cmd.size())return _ * f;
		}
		cutPlace = p;
		if (p >= cmd.size())return _ * f;
	}
	return _ * f;
}
signed main() {
	for (int i = 0; i < 0; i++) {
		system("cls");
		if (i % 2 == 0)puts("init...");
		else puts("init..");
		Sleep(1000);
		//ChangeFinger(0, 0);
	}
	ChangeFinger(0, 0);
	puts("----------------------------------------");
	puts("  ____                 _       _       ");
	puts(" / ___ | __ _  ___ _   _| | __ _| |_ ___");
	puts("| |   / _` |/ __| | | | |/ _` | __/ _ \\");
	puts("| |__| (_| | (__| |_| | | (_| | ||  __/");
	puts(" \\____\\__,_|\\___|\\__,_|_|\\__,_|\\__\\___|");
	puts("                                       ");
	puts("----------------------------------------");
	puts("wecome to use the Computing Geometry 2D v1.0\n");
	
	puts("Now in Coordinate system,there are:");
	bool updateCls = true;

	vector<point> pointTot;
	vector<polygon> polygonTot;
	vector<lineSegment> lineSegmentTot;
	vector<line>lineTot;
	vector<lineRay>lineRayTot;
	//vector<line>
	while (1) {
		if (updateCls) {
			ChangeFinger(0, 11);
			//
			ClearOne();
			cout << pointTot.size() << " points:\n";
			cout << "--";
			if (pointTot.size() == 0)puts("no points");
			else {
				for (register int i = 0; i < pointTot.size(); i++)pointTot[i].SimpleOutput(),cout<<"\b                                \n";
			}
			puts("");
			//
			ClearOne();
			cout << polygonTot.size() << " polygons:\n";
			ClearOne();
			if (polygonTot.size() == 0)puts("no polygons");
			else {
				for (register int i = 0; i < polygonTot.size(); i++) {
					ClearOne();
					cout << "--" << i << " size:" << polygonTot[i].GetSize() << "\n";
					ClearOne();
					cout << "----";
					polygonTot[i].OutputPoint();
					ClearOne();
					cout << endl;
				}
			}
			updateCls = false;
			
			ClearOne();
			puts("");
			ClearOne();
			puts("");
			ClearOne();
			puts("input \'PolygonL\' to creat a polygon with 3 points.");
			ClearOne();
			puts("input \'Polygon:i\' to creat a polygon with i points.");
			ClearOne();
			puts("input \'PolygonPoint:i(x,y)\' to add a point in polygon(i).");
			ClearOne();
			puts("input Point:(x,y) to creat a point.");
			ClearOne();
			puts("input Line-segment:(x1,y1,x2,y2) to creat a line-segment.");
			ClearOne();
			puts("input Line:(x1,y1,x2,y2) to creat a line.");
			ClearOne();
			puts("input Line-ray:(x1,y1,x2,y2) to creat a line-ray.");
			//先在这里加两行
		}
		ClearOne();
		string cmd;
		cin >> cmd;
		if (cmd=="PolygonL"){
			polygonTot.push_back(polygon());
		}
		else if (cmd.find("Polygon:") < cmd.size()) {
			cutPlace = 0;
			int p = (int)read(cmd);
			polygonTot.push_back(polygon(p));
		}
		else if (cmd.find("PolygonPoint:") < cmd.size()) {
			cutPlace = 0;
			int i = read(cmd);
			double x = read(cmd);
			double y = read(cmd);
			cout<<"i:"<<i<<",x:"<<x<<"y:"<<y<<endl;
			if (i > polygonTot.size())continue;
			polygonTot[i].AddPoint(point(x,y));
		}
		else if (cmd.find("Point:") < cmd.size()) {
			cutPlace = 0;
			double x = read(cmd);
			double y = read(cmd);
			pointTot.push_back(point(x, y));
		}
		else if (cmd.find("Line-segment") < cmd.size()) {
			cutPlace = 0;
			double x1 = read(cmd);
			double y1 = read(cmd);
			double x2 = read(cmd);
			double y2 = read(cmd);
			lineSegmentTot.push_back(lineSegment(x1, y1, x2, y2));
		    updateCls = true;
	     }
		else if (cmd.find("Line") < cmd.size()) {
			cutPlace = 0;
			double x1 = read(cmd);
			double y1 = read(cmd);
			double x2 = read(cmd);
			double y2 = read(cmd);
			lineTot.push_back(line(x1, y1, x2, y2));
			updateCls = true;
		}
		else if (cmd.find("Line-ray") < cmd.size()) {
			cutPlace = 0;
			double x1 = read(cmd);
			double y1 = read(cmd);
			double x2 = read(cmd);
			double y2 = read(cmd);
			lineRayTot.push_back(lineRay(x1, y1, x2, y2));
			updateCls = true;
		}
	return 0;
}