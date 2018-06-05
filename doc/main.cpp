 pid_Init(20, 0, 0, &pidData);
 pid_Reset_Integrator(&pidData);


pid_Controller(20, panT1->Caption.ToInt(), &pidData)
