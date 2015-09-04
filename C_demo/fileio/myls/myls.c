/************************************************************
功能:完成 ls -l 的功能
注意：要输入绝对路径 
主要知识点：linux C中的文件IO知识 
************************************************************/

#include "commonheader.h"

int is_file (struct stat buf);
int is_dir (struct stat buf);
void print_file_mode (const struct stat buf);
void print_file_permissions (const struct stat buf);
void print_file_nlink (const struct stat buf);
void print_file_bt_user (const struct stat buf);
void print_file_bt_grp (const struct stat buf);
void print_file_size (const struct stat buf);
void print_file_mtime (const struct stat buf);
void print_file_info (const char * filename);
void print_dir_info (const char * dirname);
int get_digit (int num);

int MaxNlinkDi = 1;
int MaxSizeDi = 1;

int main (int agrc, char *argv[])
{
	struct stat buf;
	
	stat (argv[1], &buf);

	//判断是否是文件，是则打印文件信息
	if (is_file (buf))
	{
		print_file_info (argv[1]);	
	}

	//若是目录，则打印目录下所有的文件信息，但不包括. ..文件
	if (is_dir (buf))
	{
        	
		print_dir_info (argv[1]);	
	}

	return 0;
}


void print_file_mode (const struct stat buf)
{
	switch (buf.st_mode & S_IFMT)
	{
		//block device
		case S_IFBLK:
			printf ("b");
			break;

		//character device
		case S_IFCHR:
			printf ("c");
			break;

		//directory device
		case S_IFDIR:
			printf ("d");
			break;

		//pile 
		case S_IFIFO:
			printf ("p");
			break;

		//symlink
		case S_IFLNK:
			printf ("l");
			break;

		//regular file
		case S_IFREG:
			printf ("-");
			break;

		//socket
		case S_IFSOCK:
			printf ("s");
			break;

		//unknown
		default :
			printf ("unknown?\n");
			break;
	}
}


//打印用户权限
void print_user_permission (const struct stat buf)
{
	char suid = 0;
	
	if ( S_ISUID == (buf.st_mode & S_ISUID) )
	{
		suid = 1;
	}


	switch ( (buf.st_mode & S_IRWXU) )
	{
		case S_IRUSR:
			if (suid)
			{
				printf ("r-S");
			}
			else
			{
				printf ("r--");
			}
			break;

		case S_IWUSR:
			if (suid)
			{
				printf ("-wS");
			}
			else
			{
				printf ("-w-");
			}
			break;
		case S_IXUSR:
			if (suid)
			{
				printf ("--s");
			}
			else
			{
				printf ("--x");
			}
			break;

		case S_IRUSR | S_IWUSR:
			if (suid)
			{
				printf ("rwS");
			}
			else
			{
				printf ("rw-");	
			}
			break;

		case S_IRUSR | S_IXUSR:
			if (suid)
			{
				printf ("r-s");
			}
			else
			{
				printf ("r-x");	
			}
			break;

		case S_IWUSR | S_IXUSR:
			if (suid)
			{
				printf ("-ws");
			}
			else
			{
				printf ("-wx");	
			}
			break;

		case S_IRWXU:
			if (suid)
			{
				printf ("rws");
			}
			else
			{
				printf ("rwx");
			}
			break;

		default:
			printf ("unkown!\n");	
			break;

	}
}


//打印用户组权限
void print_group_permission (const struct stat buf)
{
	char sgid = 0;
	
	if ( S_ISGID == (buf.st_mode & S_ISGID) )
	{
		sgid = 1;
	}


	switch ( (buf.st_mode & S_IRWXG) )
	{
		case S_IRGRP:
			if (sgid)
			{
				printf ("r-S");
			}
			else
			{
				printf ("r--");
			}
			break;

		case S_IWGRP:
			if (sgid)
			{
				printf ("-wS");
			}
			else
			{
				printf ("-w-");
			}
			break;

		case S_IXGRP:
			if (sgid)
			{
				printf ("--s");
			}
			else
			{
				printf ("--x");
			}
			break;

		case S_IRGRP | S_IWGRP:
			if (sgid)
			{
				printf ("rwS");
			}
			else
			{
				printf ("rw-");	
			}
			break;

		case S_IRGRP | S_IXGRP:
			if (sgid)
			{
				printf ("r-s");
			}
			else
			{
				printf ("r-x");	
			}
			break;

		case S_IWGRP | S_IXGRP:
			if (sgid)
			{
				printf ("-ws");
			}
			else
			{
				printf ("-wx");	
			}
			break;

		case S_IRWXG:
			if (sgid)
			{
				printf ("rws");
			}
			else
			{
				printf ("rwx");
			}
			break;

		default:
			printf ("unkown!\n");	
			break;

	}
}


//打印其它人权限
void print_other_permission (const struct stat buf)
{
	char svtx = 0;
	
	if ( S_ISVTX == (buf.st_mode & S_ISVTX) )
	{
		svtx = 1;
	}

	switch ( (buf.st_mode & S_IRWXO) )
	{
		case S_IROTH:
			if (svtx)
			{
				printf ("r-T");
			}
			else
			{
				printf ("r--");
			}
			break;

		case S_IWOTH:
			if (svtx)
			{
				printf ("-wT");
			}
			else
			{
				printf ("-w-");
			}
			break;

		case S_IXOTH:
			if (svtx)
			{
				printf ("--t");
			}
			else
			{
				printf ("--x");
			}
			break;

		case S_IROTH | S_IWOTH:
			if (svtx)
			{
				printf ("rwT");
			}
			else
			{
				printf ("rw-");	
			}
			break;

		case S_IROTH | S_IXOTH:
			if (svtx)
			{
				printf ("r-t");
			}
			else
			{
				printf ("r-x");	
			}
			break;

		case S_IWOTH | S_IXOTH:
			if (svtx)
			{
				printf ("-wt");
			}
			else
			{
				printf ("-wx");	
			}
			break;

		case S_IRWXO:
			if (svtx)
			{
				printf ("rwt");
			}
			else
			{
				printf ("rwx");
			}
			break;

		default:
			printf ("unkown!\n");	
			break;

	}
}

/******************************************************
 *who: 0->user 1->group 2->others
 * ****************************************************/
void print_permission(const struct stat buf, const int who)
{

	if (0 == who)//打印用户的权限
	{
		print_user_permission(buf);	
	
	}
	else if (1 == who) //打印用户组权限
	{
	
		print_group_permission(buf);	
	}
	else if (2 == who) //打印其它人的权限
	{
	
		print_other_permission(buf);	
	}

}

void print_file_permissions (const struct stat buf)
{
	
	//user permissions
	print_user_permission(buf);	
	//print_permission(buf, 0);


	//group permissions
	print_group_permission(buf);	
	//print_permission(buf, 1);


	//other permissions
	print_other_permission(buf);	
	//print_permission(buf, 2);
}


void print_file_nlink (const struct stat buf)
{
	printf("%d", (int)buf.st_nlink);
}

void print_file_bt_user (const struct stat buf)
{
	struct passwd *pTmp = getpwuid (buf.st_uid);
	printf ("%s", pTmp->pw_name);
}

void print_file_bt_grp (const struct stat buf)
{
	struct group *pTmp = getgrgid (buf.st_gid);
	printf ("%s", pTmp->gr_name);
}


void print_file_size (const struct stat buf)
{
	char buff[15];

	sprintf (buff, "%c%d%c", '%', MaxSizeDi, 'd');
	printf (buff, (int)buf.st_size);
}

void print_file_mtime (const struct stat buf)
{
	char buff[30];
	int strlength = 0;

	sprintf (buff, "%s", ctime(&buf.st_mtime));

	//除去掉时间字符串中的换行符
	strlength = strlen(buff);	
	buff[strlength-1] = '\0';

	printf ("%s", buff);
}

//不带路径地打印出文件名
void print_file_name (char * filename)
{
	char *pTmp = filename;
	int fi_path_len = strlen (filename);
	char *pName =NULL; 
	int i;
	char ch;
	

	if ('/' != pTmp[0]) 
	{
		printf ("%s", filename);
	}	
	else
	{
		//找到字符串最后一个/符号的位置
		for (i=fi_path_len; i>0; --i)
		{
			if ('/' == pTmp[i])
			{
				break;
			}

		}
		pName = &pTmp[i+1];
		printf ("%s", pName);

	}
}

void print_file_info (const const char * filename)
{
	struct stat buf;

	//获取文件的stat结构
	stat (filename, &buf);

	//打印出文件类型
	print_file_mode (buf);
	   

	//打印储存权限
	print_file_permissions (buf);

	//打印数目
	printf (" ");
	print_file_nlink (buf);	

	//打印文件从属
	printf (" ");
	print_file_bt_user (buf);
	printf (" ");
	print_file_bt_grp (buf);

	//打印文件大小
	printf (" ");
	print_file_size (buf);

	//打印时间
	printf(" ");
	print_file_mtime (buf);
	
	//打印文件名
	printf (" ");
	
	print_file_name((char *)filename);
	printf ("\n");
}


int is_file (struct stat buf)
{
	return (S_IFREG == (S_IFREG & buf.st_mode));
}

int is_dir (struct stat buf)
{
	return (S_IFDIR == (S_IFDIR & buf.st_mode));
}


int get_digit (int num)
{
	int count = 0; 
	
	while (0 != num)
	{
		count++;
		num /=10;
	}

	return count;
}

void print_dir_info (const char * dirname)
{
	char file_path[100];
	struct stat buf;
	struct dirent *pTmp;
	int MaxNlink = 1;
	int MaxSize = 0;

	
	DIR *pDir = opendir (dirname);
	//设置打印格式的width
	while ( NULL != (pTmp = (readdir (pDir))) )
	{
		bzero (file_path, sizeof(file_path));
		sprintf (file_path, "%s%s", dirname, pTmp->d_name);
        stat (file_path, &buf);
	    
		if (buf.st_size > MaxSize)
		{
			MaxSize = buf.st_size;
		}

		if (buf.st_nlink > MaxNlink)
		{
			MaxNlink = buf.st_nlink;
		}
		
	}

	MaxSizeDi = get_digit (MaxSize);
	MaxNlinkDi = get_digit (MaxNlink);
	closedir (pDir);

	pDir = opendir (dirname);
	
	while ( NULL != (pTmp = (readdir (pDir))) )
	{
		//获取文件名
		if ( 0 != strcmp (pTmp->d_name, ".") && 
		     0 != strcmp (pTmp->d_name, "..") )
		{
			bzero(file_path, sizeof(file_path));
			sprintf(file_path,"%s/%s", dirname, pTmp->d_name);
			print_file_info (file_path);

		}

	}

	closedir (pDir);
}
