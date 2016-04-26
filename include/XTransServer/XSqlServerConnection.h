#pragma once
#ifndef __XSQLSERVERCONNECTION_H__
#define __XSQLSERVERCONNECTION_H__

#define OTL_ODBC_MSSQL_2008
#define OTL_STL
//#define OTL_ANSI_CPP
#define OTL_MAX_CHAR_SIZE 1024

#ifdef _WIN32 
#define OTL_BIGINT int64_t
#define OTL_UBIGINT uint64_t
#endif

//#define OTL_STREAM_POOLING_ON
#include "otlv4.h"

class XSqlServerConnection : public XDataBaseConnection
{
public:
	static XDataBaseConnection* CreateInstance()
	{ 
		return new XSqlServerConnection();
	};
	static XRegistyDataBaseConnectionClass xRegisty;

public:
	XSqlServerConnection(void);
	~XSqlServerConnection(void);

	int Initialize();
	int Terminate();
	// ����SqlServer���ݿ�
	int Open(string strConnectString);

	// �ر�SqlServer���ݿ�
	int Close();

	// ��ѯָ��SQL
	int Query(string strSql, int iArraySize, XDataTable &xDataTable);

	// ִ��ָ��SQL
	int ExecuteSql(string strSql, int64_t &i64RecordCount);

	//��ʼ����
	int BeginTransaction();

	// �ύ����
	int Commit();

	// �ع�����
	int RollBack();

	// ����
	int HeartBeat();

private:
	static int ToXDataTable(otl_stream &os, XDataTable &xDataTable);
	otl_connect db;
};

//#undef OTL_ODBC_MSSQL_2008
//#undef OTL_STL
//#undef OTL_ANSI_CPP
////#undef OTL_MAX_CHAR_SIZE

#endif //__XORACLECONNECTION_H__
