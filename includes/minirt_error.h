#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERROR_NO_ARG			"Scene description file not specified"
# define ERROR_NO_RT_FILE		"No scene description file specified"
# define ERROR_BAD_FORMAT		"Incorrect formatting of the scene description file"
# define ERROR_RGB_FORMAT		"Incorrect RGB color formatting"
# define ERROR_VEC_FORMAT		"Incorrect vector formatting"

# define ERROR_FILE_OPEN		"Failed to open scene description file"
# define ERROR_FILE_READING		"Unable to read scene description file"
# define ERROR_FILE_CLOSE		"Failed to close scene description file"

# define ERROR_UNIQUE			"Identifiers A, C, and L are unique."

# define ERROR_OUT_OF_RANGE		"Invalid set value range"

# define ERROR_WRONG_DATA		"Invalid config data"

# define ERROR_INVALID_CHAR		"Only spaces, real numbers, commas, and symbols can be used after the identifier."

void	ft_error(char *error_detail);
void	*ft_calloc_assert(size_t count, size_t size);

#endif
