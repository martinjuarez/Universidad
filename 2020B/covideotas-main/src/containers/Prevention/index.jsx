import React from 'react';

import saludLogo from '../../images/saludLogo.png'

import useStyles from './style';

import { Header, InfoCard } from '../../components';

const Prevention = () => {
  const classes = useStyles();

  return (
    <div className={classes.root}>
      <Header />
      <div className={classes.infoCard}>
        <InfoCard />
      </div>
      <div className={classes.container}>
        <div className={classes.infoContainer}>
          <div className={classes.imgLogo}>
            <img alt="saludLogo" src={saludLogo} />
          </div>
          <div>
            <div className={classes.generalInfo}>
              Toma las precauciones adecuadas e infórmate bien para protegerte y cuidar de quienes te rodean. Sigue las recomendaciones de los organismos de salud pública de tu zona.
          </div>
            <div className={classes.title}>
              Para evitar la propagación de la COVID-19:
          </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>Lávate las manos con frecuencia. Usa agua y jabón o un desinfectante de manos a base de alcohol.</div>
            </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>Mantén una distancia de seguridad con personas que tosan o estornuden.</div>
            </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>Utiliza mascarilla cuando no sea posible mantener el distanciamiento físico.</div>
            </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>No te toques los ojos, la nariz ni la boca.</div>
            </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>Cuando tosas o estornudes, cúbrete la nariz y la boca con el codo flexionado o con un pañuelo.</div>
            </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>Si no te encuentras bien, quédate en casa.</div>
            </div>
            <div className={classes.list}>
              <div className={classes.dot} />
              <div className={classes.listItem}>En caso de que tengas fiebre, tos o dificultad para respirar, busca atención médica.</div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Prevention;
