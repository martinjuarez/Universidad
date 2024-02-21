import { makeStyles } from '@material-ui/core/styles';

export default makeStyles((theme) => ({
  root: {
    backgroundColor: '#F8F8F8',
    height: 'calc(100vh - 50px)',
    width: '100vw',
    paddingTop: '50px',
  },
  infoCard: {
    position: 'absolute',
    top: '100px',
  },
  symptomInfo: {
    display: 'flex',
    margin: 'auto',
    width: '720px',
  },
  tired: {
    backgroundColor: '#FFE4EF',
    borderRadius: '25px',
    width: '220px',
    paddingTop: '50px',
    margin: '0px 10px',
  },
  tiredImg: {
    textAlign: 'center',
    ' & > img': {
      width: '100px',
      height: '100px',
    }
  },
  descritpion: {
    backgroundColor: '#FFFFFF',
    borderRadius: '25px',
    padding: '20px',
  },
  title: {
    color: '#261D56',
    fontSize: '18px',
    fontWeight: 'bold',
    marginBottom: '20px',
  },
  body: {
    color: '#261D56',
    fontSize: '14px',
  },
  tiredBar: {
    backgroundColor: '#71D7FF',
    width: '100%',
    height: '6px',
    borderRadius: '25px',
    margin: '20px 0px 20px 0px'
  },
  fever: {
    backgroundColor: '#FFECD6',
    borderRadius: '25px',
    width: '220px',
    paddingTop: '50px',
    margin: '0px 10px',
  },
  feverImg: {
    textAlign: 'center',
    ' & > img': {
      width: '100px',
      height: '100px',
    }
  },
  feverdBar: {
    backgroundColor: '#FFB882',
    width: '100%',
    height: '6px',
    borderRadius: '25px',
    margin: '20px 0px 20px 0px'
  },
  cough: {
    backgroundColor: '#DDE0FF',
    borderRadius: '25px',
    width: '220px',
    paddingTop: '50px',
    margin: '0px 10px',
  },
  coughImg: {
    textAlign: 'center',
    ' & > img': {
      width: '100px',
      height: '100px',
    }
  },
  coughdBar: {
    backgroundColor: '#FF8FBA',
    width: '100%',
    height: '6px',
    borderRadius: '25px',
    margin: '20px 0px 20px 0px'
  },
  faqContainer: {
    display: 'flex',
    alignItems: 'center',
    width: '815px',
    margin: '40px auto',
  },
  faq: {
    color: '#6D7278',
    fontSize: '16px',
    width: '500px',
    fontWeight: 'bold',
    '& > div': {
      margin: '10px 0px'
    }
  },
  faqIcon: {
    '& > img': {
      width: '300px',
      height: '300px',
    }
  }
}));
