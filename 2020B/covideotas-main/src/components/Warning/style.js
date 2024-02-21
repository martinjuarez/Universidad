import { makeStyles } from '@material-ui/core/styles';

export default makeStyles((theme) => ({
  root: {
    position: 'absolute',
    bottom: '0',
    left: '450px',
    backgroundColor: '#F2FBFE',
    margin: '20px',
    display: 'flex',
    padding: '10px',
    alignItems: 'center',
    width: '600px',
    borderRadius: '25px',
    '& > div': {
      margin: '0px 10px',
    }
  },
  icon: {
    '& > svg': {
      fontSize: '70px'
    }
  },
  title: {
    color: '#555965',
    fontSize: '17px',
    fontWeight: 'bold',
    marginBottom: '20px',
  },
  body: {
    color: '#555965',
    fontSize: '14px',
  },
}));
