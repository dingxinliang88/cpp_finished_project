#include "Interface.h"

int Interface::MainFace()	//系统主界面
{
	cout << "	######################欢 迎 使 用######################	" << endl
		<< "	#	1.登陆			0.退出		      #	" << endl
		<< "	#######################################################	" << endl;
	int op_num;
	cin >> op_num;
	return op_num;
}


int Interface::AdminMainFace()//管理员主界面
{
	cout << "	######################操 作 提 示######################	" << endl
		<< "	#	1.图书管理	2.学生管理	0.退出        #	" << endl
		<< "	#######################################################	" << endl;
	int op_num;
	cin >> op_num;
	return op_num;
}

int Interface::StuMainFace()//学生主界面
{
	cout << endl;
	cout << "	###########################################	" << endl;
	cout << "	#                                         #	" << endl;
	cout << "	# 1.我的信息  # 2.图书信息  # 3.借阅书籍  #	" << endl;
	cout << "	# 4.归还书籍  # 5.预约书籍  # 0.退出      #	" << endl;
	cout << "	#                                         #	" << endl;
	cout << "	###########################################	" << endl;
	int op_num;
	cin >> op_num;
	return op_num;
}

int Interface::PersonalInfoFace()//学生个人操作子界面
{
	cout << endl;
	cout << "	######################操 作 提 示######################	" << endl
		<< "	# 1.在借书籍  2.借阅记录  3.我的预约  0.退出          #	" << endl
		<< "	#######################################################	" << endl;
	int op_num;
	cin >> op_num;
	return op_num;
}

void Interface::BookLoadFace()//图书管理主界面
{
	cout << endl << endl;
	cout << "		             图书信息管理       					" << endl << endl;
	cout << "	#######################################################	" << endl;
	cout << "	#                                                     #	" << endl;
	cout << "	# 1.添加图书记录  # 2.删除书籍记录  # 3.修改书籍信息  #	" << endl;
	cout << "	# 4.查询书籍记录  # 5.显示图书记录  # 6.退出          #	" << endl;
	cout << "	#                                                     #	" << endl;
	cout << "	#######################################################	" << endl;

}

void Interface::StuLoadFace()//学生管理主界面
{
	cout << endl << endl;
	cout << "		             学生信息管理       					" << endl << endl;
	cout << "	#######################################################	" << endl;
	cout << "	#                                                     #	" << endl;
	cout << "	# 1.添加学生记录  # 2.删除学生记录  # 3.修改学生信息  #	" << endl;
	cout << "	# 4.查询学生记录  # 5.显示学生记录  # 6.退出          #	" << endl;
	cout << "	#                                                     #	" << endl;
	cout << "	#######################################################	" << endl;

}

void Interface::BookSubLoadFace2()	//图书管理子界面2			文件为空，添加记录时的界面
{
	cout << endl << endl;
	cout << "	======================操 作 提 示======================	" << endl
		<< "	|	1.添加图书记录	|	6.退出                 |	" << endl
		<< "	=======================================================	" << endl;
	cout << endl;
}

void Interface::StuSubLoadFace2()	//学生管理子界面2			文件为空，添加记录时的界面
{
	cout << endl << endl;
	cout << "	======================操 作 提 示======================	" << endl
		<< "	|	1.添加学生记录	|	6.退出                 |	" << endl
		<< "	=======================================================	" << endl;
	cout << endl;
}

void Interface::BookSubLoadFace()//图书管理子界面
{
	cout << endl << endl;
	cout << "	=======================操  作  提  示========================" << endl
		<< "	|  1.添加图书记录  |  2.删除图书记录  |   3.修改图书记录    |" << endl
		<< "	|  4.查询书籍记录  |  5.显示书籍记录  |   6.退出            |" << endl
		<< "	=============================================================" << endl;
	cout << endl;
}

void Interface::StuSubLoadFace()//学生管理子界面
{
	cout << endl << endl;
	cout << "	=======================操  作  提  示========================" << endl
		<< "	|  1.添加学生记录  |  2.删除学生记录  |   3.修改学生记录    |" << endl
		<< "	|  4.查询学生记录  |  5.显示学生记录  |   6.退出            |" << endl
		<< "	=============================================================" << endl;
	cout << endl;
}

char Interface::ReadFromFileFace()		//提示导入文件界面
{
	char op;
	cout << "要导入文件吗？(Y/N):";
	cin >> op;
	return op;
}

char Interface::AfterReadFromFileFace()	//导入之后提示显示界面
{
	char temp;
	cout << "已经成功导入，要显示资料吗？(Y/N)";
	cin >> temp;
	return temp;
}

char Interface::WriteIntoFileFace()//提示保存文件界面
{
	char temp;
	cout << "要保存数据吗？(Y/N)";
	cin >> temp;
	return temp;
}

int Interface::OperateFace()//操作输入界面			返回结果1-6代表不同操作
{
	string op;
	int flag, nflag;

	do
	{
		flag = 0; nflag = 0;
		if (nflag)
		{
			cout << "超出范围...Again:";
			cin >> op;
		}
		else
		{
			cout << "输入你的操作: ";
			cin >> op;
		}
		
		if (op.length() != 1) {
			flag++;
			nflag++;
		}
		if (op[0] > '6' || op[0] < '0') { 
			flag++;
			nflag++;
		}
	} while (flag);

	return op[0] - '0';
}

int Interface::OperateFace2()		//操作输入界面2		文件为空，添加记录时的操作提示，返回1或6
{
	string op;
	int flag, nflag = 0;

	do
	{
		flag = 0;
		if (nflag)
		{
			cout << "超出范围...Again:";
			cin >> op;
		}
		else
		{
			cout << "输入你的操作: ";
			cin >> op;
		}

		if (op.length() != 1) { 
			flag++;
			nflag++; 
		}
		if (op[0] != '6' && op[0] != '1') { 
			flag++;
			nflag++; 
		}
	} while (flag);

	return op[0] - '0';
}

int Interface::AddFace()									//添加界面，返回要添加的数目
{
	int num;
	cout << "请输入要添加的数目：(退出:-1; 批量添加：0;)";
	cin >> num;
	return num;
}


int Interface::DelFace()									//删除界面，返回序号
{
	int index;
	cout << "请输入要删除的记录序号：(输入0退出)";
	cin >> index;
	return index;
}


int Interface::BookSetFace()								//图书设置界面，返回结果 0-7
{
	int index;
	cout << "请输入要修改的书籍序号(输入0退出)";
	cin >> index;
	if (index)
	{
		cout << "要修改哪部分信息？(1.书号,2.书名,3.作者,4.出版社,5.出版日期,6.库存量,7.全部修改 0.退出)" << endl;
		cout << "输入：";
	}
	return index;
}

int Interface::StuSetFace()									//学生设置界面，返回结果 0-7
{
	int index;
	cout << "请输入要修改的学生序号(输入0退出)";
	cin >> index;
	if (index)
	{
		cout << "要修改哪部分信息？(1.学号,2.姓名,3.年龄,4.班级,5.专业,6.联系方式,7.全部修改 0.退出)" << endl;
		cout << "输入：";
	}
	return index;
}

int Interface::BookSearchFace()								//图书搜索界面，返回结果0-5
{
	int no;
	cout << "输入要搜索的类型" << endl << "1.书号2.书名3.作者4.出版社5.出版日期 0.退出" << endl;
	cout << "类型：";
	cin >> no;
	return no;
}

int Interface::StuSearchFace()								//学生搜索界面，返回结果0-5
{
	int no;
	cout << "输入要搜索的类型" << endl << "1.学号，2.姓名，3.年龄，4.班级，5.专业，0.退出" << endl;
	cout << "类型：";
	cin >> no;
	return no;
}

void Interface::AfterSearchFace()						//搜索结果显示界面
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++) {
		cout << "-";
	}
	cout << "搜索结果：";
	for (i = 0; i < 50; i++) { 
		cout << "-"; 
	}
	cout << endl;
}