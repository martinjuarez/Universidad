import React from 'react';

import sleep from '../../images/sleep.svg'
import fiebre from '../../images/fiebre.svg'
import tos from '../../images/tos.svg'
import medicine from '../../images/medicine.svg'

import { Header, InfoCard } from '../../components';

import useStyles from './style';

const Symptom = () => {
  const classes = useStyles();

  return (
    <div className={classes.root}>
      <Header />
      <div className={classes.infoCard}>
        <InfoCard />
      </div>
      <div className={classes.symptomInfo}>
        <div className={classes.tired}>
          <div className={classes.tiredImg}>
            <img alt="sleep" src={sleep} />
          </div>
          <div className={classes.descritpion}>
            <div className={classes.title}>
              Cansancio
            </div>
            <div className={classes.body}>
              Las personas con fiebre, tos y dificultad para respirar deben buscar atención médica.
            </div>
            <div className={classes.tiredBar} />
          </div>
        </div>
        <div className={classes.fever}>
          <div className={classes.feverImg}>
            <img alt="fiebre" src={fiebre} />
          </div>
          <div className={classes.descritpion}>
            <div className={classes.title}>
              Fiebre
            </div>
            <div className={classes.body}>
              Las personas con fiebre, tos y dificultad para respirar deben buscar atención médica.
            </div>
            <div className={classes.feverdBar} />
          </div>
        </div>
        <div className={classes.cough}>
          <div className={classes.coughImg}>
            <img alt="tos" src={tos} />
          </div>
          <div className={classes.descritpion}>
            <div className={classes.title}>
              Tos Seca
            </div>
            <div className={classes.body}>
              Las personas con fiebre, tos y dificultad para respirar deben buscar atención médica.
            </div>
            <div className={classes.coughdBar} />
          </div>
        </div>
      </div>
      <div className={classes.faqContainer}>
        <div className={classes.faq}>
          <div>
            Línea de atención telefónica COVID-19
            El Sistema de Atención Médica de Urgencias fue el encargado de reunir a un equipo de médicos y enfermeros para atender la línea directa sobre el coronavirus.
      </div>
          <div>
            Si requieres orientación o tienes síntomas, llama a la línea de atención directa: 33 3823 3220, disponible las 24 horas del día.
      </div>
          <div>
            Ayúdales a hacer su trabajo lo mejor posible: no realices llamadas falsas.
      </div>
          <div>
            ¿Qué hago si tengo síntomas?
            ¿A donde puedo acudir a hacerme la prueba del COVID-19?
            ¿Cuáles son las medidas de seguridad?
      </div>
        </div>
        <div className={classes.faqIcon}>
          <img alt="medicine" src={medicine} />
        </div>
      </div>
    </div>
  );
};

export default Symptom;
