/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:25:38 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:15:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** DESCRIPTION
** The iscntrl() function tests for any control character.
**
** In the ASCII character set, this includes the following characters
** (preceded by their numeric values, in octal):
**
** 000 NUL       001 SOH       002 STX       003 ETX       004 EOT
** 005 ENQ       006 ACK       007 BEL       010 BS        011 HT
** 012 NL        013 VT        014 NP        015 CR        016 SO
** 017 SI        020 DLE       021 DC1       022 DC2       023 DC3
** 024 DC4       025 NAK       026 SYN       027 ETB       030 CAN
** 031 EM        032 SUB       033 ESC       034 FS        035 GS
** 036 RS        037 US        177 DEL
**
** RETURN VALUES
** The iscntrl() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

int	ft_iscntrl(int c)
{
	if ((00 <= c && c <= 037) || c == 0177)
		return (1);
	return (0);
}
