#include "ft_ls.h"

static char	*puttime(time_t tm_file)
{
}

static char	*putyear(time_t tm_file)
{
}

char		*get_time(time_t tm_file)
{
	char		*str;
	static char	*(*f)(time_t);
	time_t		tm_now;
	time_t		tm_diff;
	struct tm	*stm_diff;

	if ((tm_now = time() == -1)
		return (NULL); 
	if ((tm_diff = tm_now - tm_file) < 0)
		return (NULL);
	if (!(stm_diff = localtime(&tm_diff))
		return (NULL);
	if ((stm_diff->tm_mon >= 6) || (stm_diff->tm_year > 0))
		f = putyear;
	else
		f = puttime;
	if (!(str = *f(tm_file))
		return (NULL);
	return (str);

