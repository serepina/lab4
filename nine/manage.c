/*
 * lab4 9번 문제
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h> 

int main() {
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	char query[80], name[20], pnum[11], address[30];
	int id, i, fields; 
	char meun[6];

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "user", "123456", "manage", 0, (char *)NULL, 0)) { 
		printf("MySQL Error %d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
		exit(1);
	}
	while(1){
		printf("INSERT/UPDATE/SELECT/EXIT.\n> ");
		scanf("%s", meun);
		if(!strcmp(meun,"INSERT")){
			printf("Input id, name, pnum, address.\n> ");
			scanf("%d %s %s %s", &id, name, pnum, address);
			sprintf(query, "insert into manage values(%d, \'%s\', \'%s\', \'%s\')", id, name, pnum, address); 
			if (mysql_query(&mysql, query)) {
				printf("MySQL Error %d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
				exit(1);
			}
			if (mysql_query(&mysql, "select * from manage")) {
				printf("MySQL Error %d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
				exit(1);
			}
			res = mysql_use_result(&mysql);
			fields = mysql_num_fields(res);
			printf("Total manage data.\n");
			while ((row = mysql_fetch_row(res))) {
				for (i = 0; i < fields; ++i) {
					printf("%12s ", row[i]);
				} 
				printf("\n"); 
			}
			mysql_free_result(res); 
		}
		else if(!strcmp(meun,"UPDATE")){
			printf("Input id\n> ");
			scanf("%d", &id);
			printf("Input change address data\n> ");
			scanf("%s", address);
			sprintf(query, "update manage set address=\'%s\' where id=%d",address, id);
			if (mysql_query(&mysql, query)) {
				printf("Error %d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
				exit(1);
			}
			printf("query info: %s\n", mysql_info(&mysql));
			printf("affected rows: %lu\n", (unsigned long) mysql_affected_rows(&mysql));
		}
		else if(!strcmp(meun,"SELECT")){
			sprintf(query, "select * from manage");
			if (mysql_query(&mysql, query)) {
				printf("MySQL Error %d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
				exit(1);
			}
			res = mysql_use_result(&mysql);
			fields = mysql_num_fields(res);
			printf("The manage date show.\n"); 

			while ((row = mysql_fetch_row(res))) {
				for (i = 0; i < fields; ++i) {
					printf("%12s ", row[i]);
				}
				printf("\n");
			}
			mysql_free_result(res); 
		}
		else if(!strcmp(meun,"EXIT")){
			printf("종료합니다.\n");
			exit(1);
		}
		else {
			printf("다시입력하세요.\n");
		}
	}
	mysql_close(&mysql);
	return 0; 
}

