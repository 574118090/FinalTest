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
	for (int i = 0; i < 2; i++) {
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
	double ans = 0;
	while (1) {
		if (updateCls) {
			ChangeFinger(0, 11);
			//
			ClearOne();
			cout << pointTot.size() << " points:\n";
			if (pointTot.size() == 0)puts("no points");
			else {
				for (register int i = 0; i < pointTot.size(); i++)pointTot[i].SimpleOutput(),cout<<"\b                                \n";
			}
			ClearOne();
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
			ClearOne();
			puts("");
			//
			ClearOne();
			cout << lineSegmentTot.size() << " Line segments:\n";
			ClearOne();
			if (lineSegmentTot.size() == 0)puts("no line segments");
			else {
				for (int i = 0; i < lineSegmentTot.size(); i++) {
					lineSegmentTot[i].Output();
				}
			}
			ClearOne();
			puts("");
			//
			ClearOne();
			cout << lineRayTot.size() << " Line ray:\n";
			ClearOne();
			if (lineRayTot.size() == 0)puts("no line ray");
			else {
				for (int i = 0; i < lineRayTot.size(); i++) {
					lineRayTot[i].Output();
				}
			}
			ClearOne();
			puts("");

			//
			ClearOne();
			cout << lineTot.size() << " Line:\n";
			ClearOne();
			if (lineTot.size() == 0)puts("no line");
			else {
				for (int i = 0; i < lineTot.size(); i++) {
					lineTot[i].Output();
				}
			}
			puts("");
			//updateCls = false;
			
			ClearOne();
			puts("");
			ClearOne();
			puts("");
			ClearOne();
			puts("input PolygonL to creat a polygon with 3 points.");
			ClearOne();
			puts("input Polygon:i to creat a polygon with i points.");
			ClearOne();
			puts("input PolygonPoint:i(x,y) to add a point in polygon(i).");
			ClearOne();
			puts("input Point:(x,y) to creat a point.");
			ClearOne();
			puts("input InPolygon(a,b) to find if point b in polygon a");
			ClearOne();
			puts("input Line-segment:(x1,y1,x2,y2) to creat a line-segment.");
			ClearOne();
			puts("input Line:(x1,y1,x2,y2) to creat a line.");
			ClearOne();
			puts("input Line-ray:(x1,y1,x2,y2) to creat a line-ray.");
			ClearOne();
			puts("input Cross(a,b) to get cross between point a and point b");
			ClearOne();
			puts("input Distance(a,b) to get distance between point a and point b");
			ClearOne();
			puts("input ifCross(a,b) to get cross between point a and point b");
			ClearOne();
			puts("input Intersect(a,b) to find if line segment a and b are intersected");
			ClearOne();
			puts("input GetS(a) to get S of polygon a");
			ClearOne();
			puts("input GetC(a) to get C of polygon a");
			ClearOne();
			puts("");
			ClearOne();
			puts("");
			ClearOne();
			cout << "ans = " << ans << endl;
			//先在这里加两行
		}
		ClearOne();
		string cmd;
		cin >> cmd;
		if (cmd=="PolygonL"){
			polygonTot.push_back(polygon());
		}
		else if (cmd.find("PolygonPoint") < cmd.size()) {
			cutPlace = 0;
			int i = read(cmd);
			double x = read(cmd);
			double y = read(cmd);
			if (i > polygonTot.size())continue;
			polygonTot[i].AddPoint(point(x, y));
		}
		else if (cmd.find("InPolygon") < cmd.size()) {
			cutPlace = 0;
			int p = read(cmd), q = read(cmd);
			if (p > pointTot.size() || q > polygonTot.size())continue;
			ans = polygon::PointPosition(pointTot[p],polygonTot[q]);
		}
		else if (cmd.find("Polygon") < cmd.size()) {
			cutPlace = 0;
			int p = (int)read(cmd);
			polygonTot.push_back(polygon(p));
		}
		else if (cmd.find("Point") < cmd.size()) {
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
		}
		else if (cmd.find("Line-ray") < cmd.size()) {
			cutPlace = 0;
			double x1 = read(cmd);
			double y1 = read(cmd);
			double x2 = read(cmd);
			double y2 = read(cmd);
			lineRayTot.push_back(lineRay(x1, y1, x2, y2));
		}
		else if (cmd.find("Line") < cmd.size()) {
			cutPlace = 0;
			double x1 = read(cmd);
			double y1 = read(cmd);
			double x2 = read(cmd);
			double y2 = read(cmd);
			lineTot.push_back(line(x1, y1, x2, y2));
		}
		else if (cmd.find("Cross") < cmd.size()) {
			cutPlace = 0;
			int p = read(cmd), q = read(cmd);
			if (p > pointTot.size() || q > pointTot.size())continue;
			ans = point::GetCross(pointTot[p], pointTot[q]);
		}
		else if (cmd.find("Distance") < cmd.size()) {
			cutPlace = 0;
			int p = read(cmd), q = read(cmd);
			if (p > pointTot.size() || q > pointTot.size())continue;
			ans = point::GetPointDistance(pointTot[p], pointTot[q]);
		}
		else if (cmd.find("Intersect") < cmd.size()) {
			cutPlace = 0;
			int p = read(cmd), q = read(cmd);
			if (p > lineSegmentTot.size() || q > lineSegmentTot.size())continue;
			ans = lineSegmentTot[q].ifIntersect(lineSegmentTot[p]);
			ans = (ans == 2) ? 1 : 0;
		}
		else if (cmd.find("GetS") < cmd.size()) {
			cutPlace = 0;
			int p = read(cmd);
			ans = polygonTot[p].GetS();
		}
		else if (cmd.find("GetC") < cmd.size()) {
			cutPlace = 0;
			int p = read(cmd);
			ans = polygonTot[p].GetC();
		}
	}
	return 0;
}