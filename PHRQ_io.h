#ifndef _PHRQIO_H
#define _PHRQIO_H

#if defined(_WINDLL)
#define IPQ_DLL_EXPORT __declspec(dllexport)
#else
#define IPQ_DLL_EXPORT
#endif

#include <ios>
#include <iosfwd>
#include <exception>

class PhreeqcStop : std::exception
{
};

class IPQ_DLL_EXPORT PHRQ_io
{
public:
	// constructor/destructor
	PHRQ_io(void);
	virtual ~ PHRQ_io();

	// methods
	static int istream_getc(void *cookie);
	static void safe_close(std::ostream **stream_ptr);
	void close_output_ostreams(void);
	void Set_io_error_count(int i)				{this->io_error_count = i;};
	int Get_io_error_count(void)				{return this->io_error_count;};

	// output_ostream
	bool output_open(const char *file_name, std::ios_base::openmode mode = std::ios_base::out);
	void output_flush(void);
	void output_close(void);
	virtual void output_msg(const char * str);
	void Set_output_ostream(std::ostream * out)		{this->output_ostream = out;};
	std::ostream *Get_output_ostream(void)			{return this->output_ostream;};
	void Set_output_on(bool tf)						{this->output_on = tf;};
	bool Get_output_on(void)						{return this->output_on;};

	// log_ostream
	bool log_open(const char *file_name, std::ios_base::openmode mode = std::ios_base::out);
	void log_flush(void);
	void log_close(void);
	void log_msg(const char * str);
	void Set_log_ostream(std::ostream * out)		{this->log_ostream = out;};
	std::ostream *Get_log_ostream(void)				{return this->log_ostream;};
	void Set_log_on(bool tf)						{this->log_on = tf;};
	bool Get_log_on(void)							{return this->log_on;};

	// punch_ostream
	virtual bool punch_open(const char *file_name, std::ios_base::openmode mode = std::ios_base::out);
	void punch_flush(void);
	void punch_close(void);
	virtual void punch_msg(const char * str);
	void Set_punch_ostream(std::ostream * out)		{this->punch_ostream = out;};
	std::ostream *Get_punch_ostream(void)			{return this->punch_ostream;};
	void Set_punch_on(bool tf)						{this->punch_on = tf;};
	bool Get_punch_on(void)							{return this->punch_on;};
	
	// error_ostream
	bool error_open(const char *file_name, std::ios_base::openmode mode = std::ios_base::out);
	void error_flush(void);
	void error_close(void);
	virtual void error_msg(const char * str, bool stop=false);
	void Set_error_ostream(std::ostream * out)		{this->error_ostream = out;};
	std::ostream *Get_error_ostream(void)			{return this->error_ostream;};
	void Set_error_on(bool tf)						{this->error_on = tf;};
	bool Get_error_on(void)							{return this->error_on;};
	void warning_msg(const char *err_str);

	// dump_ostream
	bool dump_open(const char *file_name, std::ios_base::openmode mode = std::ios_base::out);
	void dump_flush(void);
	void dump_close(void);
	void dump_msg(const char * str);
	void Set_dump_ostream(std::ostream * out)		{this->dump_ostream = out;};
	std::ostream *Get_dump_ostream(void)			{return this->dump_ostream;};
	void Set_dump_on(bool tf)						{this->dump_on = tf;};
	bool Get_dump_on(void)							{return this->dump_on;};

	// fpunchf
	virtual void fpunchf(const char *name, const char *format, double d);
	virtual void fpunchf(const char *name, const char *format, char * d);
	virtual void fpunchf(const char *name, const char *format, int d);
	virtual void fpunchf_end_row(const char *format);

	// screen_ostream
	//bool screen_open(const char *file_name, std::ios_base::openmode mode = std::ios_base::out);
	//void screen_flush(void);
	//void screen_close(void);
	virtual void screen_msg(const char * str);
	//void Set_screen_ostream(std::ostream * out)		{this->screen_ostream = out;};
	//std::ostream *Get_screen_ostream(void)			{return this->screen_ostream;};
	void Set_screen_on(bool tf)						{this->screen_on = tf;};
	bool Get_screen_on(void)						{return this->screen_on;};

	// echo 
	enum ECHO_OPTION
	{
		ECHO_LOG,
		ECHO_OUTPUT
	};
	virtual void echo_msg(const char * str);
	void Set_echo_on(bool tf)					{this->echo_on = tf;};
	bool Get_echo_on(void)						{return this->echo_on;};
	void Set_echo_destination(ECHO_OPTION eo)   {this->echo_destination = eo;};
	ECHO_OPTION Get_echo_destination(void)      {return this->echo_destination;};

	// data
protected:
	std::ostream *output_ostream;	
	std::ostream *log_ostream;		
	std::ostream *punch_ostream;	
	std::ostream *error_ostream;
	std::ostream *dump_ostream;
	//std::ostream *screen_ostream;
	int io_error_count;

	bool output_on;
	bool log_on;
	bool punch_on;
	bool error_on;
	bool dump_on;
	bool echo_on;
	bool screen_on;
	ECHO_OPTION echo_destination;
};
#endif /* _PHRQIO_H */
