void _init()
{
    if (__gmon_start__ != 0)
    {
        __gmon_start__();
    }
}

int64_t sub_1020()
{
    int64_t var_8 = data_4008;
    /* jump -> data_4010 */
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int64_t sub_1036()
{
    int64_t var_8 = 0;
    /* tailcall */
    return sub_1020();
}

uint64_t strlen(char const* arg1)
{
    /* tailcall */
    return strlen(arg1);
}

int64_t sub_1046()
{
    int64_t var_8 = 1;
    /* tailcall */
    return sub_1020();
}

char* fgets(char* buf, int32_t n, FILE* fp)
{
    /* tailcall */
    return fgets(buf, n, fp);
}

int64_t sub_1056()
{
    int64_t var_8 = 2;
    /* tailcall */
    return sub_1020();
}

void __cxa_finalize(void* d)
{
    /* tailcall */
    return __cxa_finalize(d);
}

void _start(int64_t arg1, int64_t arg2, void (* arg3)()) __noreturn
{
    int64_t stack_end_1;
    int64_t stack_end = stack_end_1;
    __libc_start_main(main, __return_addr, &ubp_av, __libc_csu_init, __libc_csu_fini, arg3, &stack_end);
    /* no return */
}

void deregister_tm_clones()
{
    return;
}

void register_tm_clones()
{
    return;
}

void __do_global_dtors_aux()
{
    if (completed.0 != 0)
    {
        return;
    }
    if (__cxa_finalize != 0)
    {
        __cxa_finalize(__dso_handle);
    }
    deregister_tm_clones();
    completed.0 = 1;
}

void frame_dummy()
{
    /* tailcall */
    return register_tm_clones();
}

uint64_t secret_func_dont_look_here(void* arg1)
{
    int32_t rax_1 = strlen(secret_data);
    int32_t var_10 = 0;
    for (int32_t i = 0; i < rax_1; i = (i + 1))
    {
        if (((*(arg1 + i) * 2) - i) != *(i + secret_data))
        {
            var_10 = 1;
        }
    }
    return var_10;
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    puts("Vous ne devinerez jamais le mot …");
    void buf;
    fgets(&buf, 0x40, stdin);
    if (secret_func_dont_look_here(&buf) == 0)
    {
        puts("Wow, impressionnant ! Vous avez …");
    }
    else
    {
        puts("C'est bien ce que je pensais, vo…");
    }
    return 0;
}

void __libc_csu_init()
{
    _init();
    int64_t i = 0;
    do
    {
        int64_t rdx;
        int64_t rsi;
        int32_t rdi;
        &__frame_dummy_init_array_entry[i](rdi, rsi, rdx);
        i = (i + 1);
    } while (1 != i);
}

void __libc_csu_fini() __pure
{
    return;
}

int64_t _fini() __pure
{
    return;
}

