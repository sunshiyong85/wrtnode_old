
extern void libip6t_DNAT_init(void);
extern void libip6t_LOG_init(void);
extern void libip6t_MASQUERADE_init(void);
extern void libip6t_REDIRECT_init(void);
extern void libip6t_REJECT_init(void);
extern void libip6t_SNAT_init(void);
extern void libip6t_icmp6_init(void);
void init_extensions6(void);
void init_extensions6(void)
{
 libip6t_DNAT_init();
 libip6t_LOG_init();
 libip6t_MASQUERADE_init();
 libip6t_REDIRECT_init();
 libip6t_REJECT_init();
 libip6t_SNAT_init();
 libip6t_icmp6_init();
}
