if (item==*"+"){
	sprintf(cells[pos], atoi(cells[pos])+1);
}
if (item==*"-"){
	sprintf(cells[pos], atoi(cells[pos])-1);
}
if (item==*">"){
	pos++;
}
if (item==*"<"){
	pos--;
}
if (item==*"."){
	printf("%s", cells[pos]);
}
if (item==*","){	
}

