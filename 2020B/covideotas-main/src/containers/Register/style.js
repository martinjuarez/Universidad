import { makeStyles } from '@material-ui/core/styles';


export default makeStyles((theme) => ({
  root: {
    backgroundColor: '#F8F8F8',
    textAlign: 'center',
    height: '100vh',
    width: '100vw',
    display: 'flex',
    justifyContent: 'center',
    alignItems: 'center',
  },
  container: {
    backgroundColor: '#FFFFFF',
    display: 'flex',
    textAlign: 'left',
    width: '900px',
    height: '500px',
    borderRadius: '10px',
    boxShadow: '0 4px 8px 0 rgba(0,0,0,0.2)',
  },
  inputContainer: {
    margin: '40px',
  },
  imgContainer: {
    margin: '40px',
  },
  title: {
    fontSize: '1.2rem',
  },
  description: {
    fontSize: '0.8rem',
  },
  input: {
    margin: '15px 0px',
  },
  button: {
    margin: '15px 0px',
  },
  img: {
    width: '400px',
    height: '400px',
  },
}));
