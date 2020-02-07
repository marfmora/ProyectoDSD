#include <stdio.h>
#include <math.h>
#include <io.h>
#include <unistd.h>
#include "system.h"
#include " "
#include <stdio.h>

/*=======  niNN vector de entrada =========*/
float niNN[5];
float DatosR[10]= {275, 143, 318, 511, 740, 795, 1230, 1290, 571, 1068};
float DatosP[10];
int x,y;
int color;
int Max=1700;
/*=======  funcion mapminmax =========*/
float *mapminmax(float input[])
{
    int i;
    float ymax=1,ymin=-1;
    float xmin[]={1,11,1,8,23,54};
    float xmax[]={30,12,7,17,30,2392};
    static float output[6];
    for(i=0;i<6;i++)
    {
        output[i]=((ymax-ymin)/(xmax[i]-xmin[i]))*(input[i]-xmin[i])+ymin;
    }
    return output;
}
/*=======  producto punto =========*/
float DotProduct(float input1[], float input2[])
{
    int i=0;
    float acumulador=0;
    for (i=0;i!=6;i++)
    {
        acumulador=input1[i]*input2[i]+acumulador;
    }
    return acumulador;
}
/*=======  tangente sigmoidal =========*/
float tansig(float input1)
{
    float tansigout=(2/(1+exp(-2*input1))-1);
    return tansigout;
}
/*=======  hidden layer =========*/
float *layer1(float *input1)
{
    float static output[10];
    float w0[]={-0.49900365352953613,0.2252990826437542,0.14998435974063867,4.4191004520812065,1.210922803699567,-3.6071313438104466};
    float w1[]={3.9648741955479458,0.45056770610722663,3.8288330330636864,-0.9789095083958661,-5.6752898183472364,1.1694289661176511};
    float w2[]={-0.69160995812383064,-0.071338879296505467,-0.20956269906829414,-2.3337093050684894,2.7360513169515785,-2.2910916173839362};
    float w3[]={-0.22136447687089519,3.7324983496105935,-3.2952664117466339,1.5369228699863495,-0.1942487998301945,-0.12980770562932975};
    float w4[]={0.23574573240260022,3.9600073379291145,-0.001370442748555023,0.89461532195008409,-4.0591649237087504,2.4802341132717158};
    float w5[]={-3.0648439248460351,1.5441829930280588,-4.0197003779278715,1.852723365512646,4.230982368081361,1.0532372911529335};
    float w6[]={2.4595326948490119,2.2089831182384483,-2.0649808966001211,0.37276074777686985,-0.69408113628150248,-1.737494361083268};
    float w7[]={0.16719111166439315,-0.17136684143631525,0.037882221231228898,-0.29164501172056922,0.098332992304010991,1.6518501487547437};
	float w8[]={0.71678883944981431,-0.041565123749393376,0.45651254624149573,2.5293512052381826,-2.433048680211841,-2.0220226652960633};
	float w9[]={2.151674162232827,-0.73490060397825363,1.6905326324379479,-1.3085815993438339,2.5292278324675985,0.15240022034861081};
	output[0]=tansig(DotProduct(input1,w0)+(3.3433284252428512));
	output[1]=tansig(DotProduct(input1,w1)+(-0.036447756811894216));
    output[2]=tansig(DotProduct(input1,w2)+(-1.3523874549924662));
    output[3]=tansig(DotProduct(input1,w3)+(-0.61839677894535661));
    output[4]=tansig(DotProduct(input1,w4)+(-3.8992560286922506));
    output[5]=tansig(DotProduct(input1,w5)+(0.60079638615964137));
    output[6]=tansig(DotProduct(input1,w6)+(-2.3368502477691875));
    output[7]=tansig(DotProduct(input1,w7)+(0.76522286478917112));
    output[8]=tansig(DotProduct(input1,w8)+(-2.3414826727455074));

output[9]=tansig(DotProduct(input1,w9)+(-3.5620741587124622));
    return output;
}
/*=======  producto punto =========*/
float DotProduct1(float input1[], float input2[])
{
    int i=0;
    float acumulador=0;
    for (i=0;i!=10;i++)
    {
        acumulador=input1[i]*input2[i]+acumulador;
    }
    return acumulador;
}
/*=======  funcion mapminreverse =========*/
float mapminreverse(float input)
{
    float ymax=1,ymin=-1;
    float xmin=54;
    float xmax=2392;
    static float output;
    output=((xmax-xmin)/(ymax-ymin))*(input-ymin)+xmin;
    return output;
}
/*=======  output layer =========*/
float layer2(float *input1)
{
    float static output1;
    float w0[]={0.47108807391247043,-0.10411755397208304,-0.1788483604827063,0.15165695129086951,-0.14409444405250621,-0.1129008447006206,-0.098924698271006944,0.3886284421745746,-0.21017457047652272,-0.055756415716755534};

output1=DotProduct1(input1,w0)+(-1.2457423263770231);
	return mapminreverse(output1);
}
/*=======  main =========*/
int main()
{

	int SS=1;
	int count=0;

    while(SS){
    	int n;
    	int dia,mes,diaS,hora;
    	float temp,ps;
    	printf("Ingresar Dia a predecir: \n");
    	scanf("%i",&dia);
    	printf("Ingresar Mes a predecir: \n");
    	printf("Los meses se escogen del 1 - 12. \n");
    	scanf("%i",&mes);
    	printf("Ingresar Dia de la semana: \n");
    	printf("Los Dias de la semana se escogen del 1 - 7. \n");
    	printf("Siendo 1 equivalente a Lunes. \n");
    	scanf("%i",&diaS);
    	printf("Ingresar Hora a predecir: \n");
    	printf("Los horarios de prediccion son de 9-20 hrs \n");
    	scanf("%i",&hora);
    	printf("Ingresar Temperatura promedio: \n");
    	scanf("%f",&temp);
    	printf("Ingresar Pasos anteriores: \n");
    	scanf("%f",&ps);

    	niNN[0]=dia;
    	niNN[1]=mes;
    	niNN[2]=diaS;
    	niNN[3]=hora;
    	niNN[4]=temp;
    	niNN[5]=ps;

    	float *GPP1=mapminmax(niNN);
    	float input1[6];
    	float input2[10];
    	for(n=0;n<6;n++)
    	{
    	    input1[n]=GPP1[n];
    	}
    	float *GPP2=layer1(input1);
    	for(n=0;n<10;n++)
    	{
    		input2[n]=GPP2[n];
    	}
    	float output=layer2(input2);
    	printf("%f\n",output);

    	DatosP[count]=output;
    	printf("Ingrese 0 para salir \n");
        printf("Ingrese 1 para predecir \n");
        scanf("%i",&SS);

    	//Efectuación de Grafica

        if (count==0) {
        	alt_up_pixel_buffer_dma_dev *pixel_dev = NULL;
        	pixel_dev =  alt_up_pixel_buffer_dma_open_dev("/dev/PIXEL_BUFFER_DMA");
        	if(pixel_dev != NULL){
        	    printf("Finish load device structure\nVGA\n\n");}
        	alt_up_pixel_buffer_dma_clear_screen(pixel_dev,0);

        	for( x = 239; x >= 0; x = x - 1){
        	   for(y = 0; y < 320; y = y + 1){
        	    	color = 0xFFFF;
        	    	alt_up_pixel_buffer_dma_draw(pixel_dev, color, y, x);
        	    }
        	}

        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 3, 230, 310, 230, 0x0000, 0); //Horizontal
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 307, 227, 307, 227, 0x0000, 0); //Horizontal
        	alt_up_pixel_buffer_dma_draw_line (pixel_dev, 307, 227, 310, 230, 0x0000, 0);
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 307, 233, 307, 233, 0x0000, 0); //Horizontal
        	alt_up_pixel_buffer_dma_draw_line (pixel_dev, 307, 233, 310, 230, 0x0000, 0);

        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 7, 10, 7, 235, 0x0000, 0); //Vertical
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 4, 13, 4, 13, 0x0000, 0); //Vertical
        	alt_up_pixel_buffer_dma_draw_line (pixel_dev, 7, 10, 4, 13, 0x0000, 0);
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 10, 13, 10, 13, 0x0000, 0); //Vertical
        	alt_up_pixel_buffer_dma_draw_line (pixel_dev, 7, 10, 10, 13, 0x0000, 0);

        	//Coordenadas Eje Vertical
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-200*240/Max),9,(230-200*240/Max), 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-400*240/Max),9,(230-400*240/Max), 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-600*240/Max),9,(230-600*240/Max), 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-800*240/Max),9,(230-800*240/Max), 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-1000*240/Max),9,(230-1000*240/Max), 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-1200*240/Max),9,(230-1200*240/Max), 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,5, (230-1400*240/Max),9,(230-1400*240/Max), 0x0000, 0); //rojo

        	//Coordenadas Eje Horizontal
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,44,228,44,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,76,228,76,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,108, 228,108,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,140,228,140,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,172,228,172,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,204,228,204,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,236, 228,236,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,268, 228,268,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev,300,228,300,232, 0x0000, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 12, (230-DatosP[count]*240/Max), 13,(230-DatosP[count]*240/Max)+1, 0x07E0, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 12, (230-DatosR[count]*240/Max), 13,(230-DatosR[count]*240/Max)+1, 0xF81F, 0); //rojo
        }else{
        	alt_up_pixel_buffer_dma_dev *pixel_dev = NULL;
        	pixel_dev =  alt_up_pixel_buffer_dma_open_dev("/dev/PIXEL_BUFFER_DMA");
        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 12+(31*count), (230-(DatosP[count]*240/Max)), 13+(31*count),(230-(DatosP[count]*240/Max))+1, 0x07E0, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_line (pixel_dev, 13+(31*(count-1)), (230-(DatosP[count-1]*240/Max))+1, 13+(31*count), (230-(DatosP[count]*240/Max)), 0x07E0, 0);

        	alt_up_pixel_buffer_dma_draw_box (pixel_dev, 12+(31*count), (230-(DatosR[count]*240/Max)), 13+(31*count),(230-(DatosR[count]*240/Max))+1, 0xF81F, 0); //rojo
        	alt_up_pixel_buffer_dma_draw_line (pixel_dev, 13+(31*(count-1)), (230-(DatosR[count-1]*240/Max))+1, 13+(31*count), (230-(DatosR[count]*240/Max)), 0xF81F, 0);
        }
        count=count+1;
    }

    printf("%s\n", "Pasos Realizados");

    for (int ii=0;ii<= count;ii++)
    {
    	printf("%f ",DatosR[ii]);
    }

    printf("%s\n", ".");
    printf("%s\n", "Pasos Predichos");

    for (int ii=0;ii<= count;ii++)
    {
    	printf("%f ",DatosP[ii]);
    }

    return 0;
}

