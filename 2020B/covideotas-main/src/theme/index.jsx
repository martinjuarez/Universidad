import React from 'react';
import PropTypes from 'prop-types';

import { createMuiTheme } from '@material-ui/core/styles';
import { ThemeProvider } from '@material-ui/styles';

const theme = createMuiTheme({
  palette: {
    primary: {
      light: '#98D3FB',
      main: '#0372BC',
      dark: '#194B6D',
    },
    secondary: {
      light: '#E1DBF3',
      main: '#8B6BEF',
      dark: '#4B4279',
    },
  },
});


const Theme = ({ children }) => <ThemeProvider theme={theme}>{children}</ThemeProvider>;

Theme.propTypes = {
  children: PropTypes.oneOfType([PropTypes.arrayOf(PropTypes.node), PropTypes.node]).isRequired,
};

export default Theme;
