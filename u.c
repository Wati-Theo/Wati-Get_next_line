char	*get_nexte_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				r;
	int				loc;
	char			*res;
	char			*tmp;

	res = NULL;
	if (!buf[0])
		r = read(fd, buf, BUFFER_SIZE);
	else
		r = 1;
	while (r > 0)
	{
		if (where_are_you(buf) > -1) //  si \n dans buf
		{
			loc = where_are_you(buf);
			tmp = sp_ft_strndup(buf, loc);
			res = ft_strjoin(res, tmp);
			if (tmp)
				free(tmp);
			if (buf[loc + 1]) // si il y a quelques chose apres le '\n'
			{
				buf[loc] = 0; // '\0' a lemplacement de l'ancien de '\n'
				get_back(buf);
				return (res);
			}
			get_zeroed(buf);
			return (res);
		}
		else
		{
			res = ft_strjoin(res, buf); // strjoin le texte lu
			r = read(fd, buf, BUFFER_SIZE);
			buf[r] = 0;
		}
	}
	return (res);
}